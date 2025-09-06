#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool isEnd;

    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string str) {
    TrieNode* curr = root;
    for (int i = 0; i < str.size(); i++) {
        int idx = str[i] - 'a';
        if (curr->child[idx] == NULL) {
            curr->child[idx] = new TrieNode();
        }
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

bool search(string key, TrieNode* root) {
    TrieNode* curr = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            return false;
        curr = curr->child[index];
    }
    return curr->isEnd;
}

TrieNode* deleteKey(string key, TrieNode* root, int i) {
    if (root == NULL) {
        return root;
    }
    if (i == key.size()) {
        root->isEnd = false;
        if (isEmpty(root)) {
            delete root;
            root = NULL;
            return root;
        }
    }
    int idx = key[i] - 'a';
    root->child[idx] = deleteKey(key, root->child[idx], i + 1);
    if (isEmpty(root) && root->isEnd == false) {
        delete root;
        root = NULL;
    }
    return root;
}

bool isEmpty(TrieNode* root) {
    for (int i = 0; i < 26; i++) {
        if (root->child[i] != NULL) {
            return false;
        }
    }
    return true;
}

int main() {
    TrieNode* root = new TrieNode();
    insert(root, "bad");
    cout << search("bat", root);
}
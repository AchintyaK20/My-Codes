#include <bits/stdc++.h>
#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long int
#define mp make_pair
#define pb push_back
#define p pair
#define vt vector
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define CEIL(a, b) (a + b - 1) / (b)
#define endl "\n"
#define db1(x) cout << #x << " = " << x << '\n';
#define db2(v)        \
    for (auto &x : v) \
        cout << x << " ";
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
using namespace std;

class TrieNode
{
public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; ++i)
        {
            child[i] = NULL;
        }
    }
};
void insert(string &key, TrieNode *root)
{
    TrieNode *curr = root;
    for (int i = 0; i < sz(key); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
        {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}
bool search(string &key, TrieNode *root)
{
    TrieNode *curr = root;
    for (int i = 0; i < sz(key); i++)
    {
        int index = key[i] - 'a';
        if (curr->child[index] == NULL)
            return false;
        curr = curr->child[index];
    }
    return curr->isEnd;
}
bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
        {
            return false;
        }
    }
    return true;
}
TrieNode *deleteNode(TrieNode *root, string &key, int i)
{
    if (root == NULL)
        return NULL;
    if (i == sz(key))
    {
        root->isEnd = false;
        if (isEmpty(root))
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
    int index = key[i] - 'a';
    root->child[index] = deleteNode(root->child[index], key, i + 1);
    if (isEmpty(root) && root->isEnd == false)
    {
        delete (root);
        root = NULL;
    }
    return root;
}
int main()
{
    int n;
    cin >> n;
    TrieNode *root = new TrieNode();
    for (int i = 0; i < n; i++)
    {
        string key;
        cin >> key;
        insert(key, root);
    }
    string key;
    cin >> key;
    cout << search(key, root) << endl;
    root = deleteNode(root, key, 0);
    cout << search(key, root);
    return 0;
}
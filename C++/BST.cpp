#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define pi pair<int, int>
#define REP(i,a,b) for (int i = a; i < b; i++)
#define F first
#define S second
#define endl "\n"
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define MOD7 1000000007
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// void LinkedListToBinaryTree(Node *head, TreeNode *&root)
// {
//     if (head == NULL)
//         return;
//     queue <TreeNode*> q;
//     root = new TreeNode(head->data);
//     q.push(root);
//     Node *curr = head->next;
//     while (curr != NULL)
//     {
//         TreeNode *parent = q.front();
//         q.pop();
//         TreeNode *temp1 = new TreeNode(curr->data);
//         parent->left = temp1;
//         q.push(temp1);
//         if (curr->next != NULL)
//         {
//             curr = curr->next;
//             TreeNode *temp2 = new TreeNode(curr->data);
//             parent->right = temp2;
//             q.push(temp2);
//         }
//         else
//         {
//             break;
//         }
//         curr = curr->next;
//     }
// }

Node* constructBstFromLevelOrder(int arr[], int n)
{
    queue <tuple<int, Node*, int>> q;
    Node *root = NULL;
    int i = 0;
    Node *newNode = new Node(arr[i++]);
    root = newNode;
    q.push({INT_MIN, newNode, INT_MAX});
    while (i < n)
    {
        int minv = get<0>(q.front());
        Node *curr = get<1>(q.front());
        int maxv = get<2>(q.front());
        q.pop();
        if (i < n && arr[i] > minv && arr[i] < curr->data)
        {
            newNode = new Node(arr[i++]);
            curr->left = newNode;
            q.push({minv, newNode, curr->data});
        }
        if (i < n && arr[i] > curr->data && arr[i] < maxv)
        {
            newNode = new Node(arr[i++]);
            curr->right = newNode;
            q.push({curr->data, newNode, maxv});
        }
    }
    return root;
}
vector<int> verticalTraversal(Node *root)
{
    vector<int> v;
    map <int, vector<int>> m;
    queue <pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *curr = it.first;
        int hd = it.second;
        m[hd].push_back(curr->data);
        if (curr->left != NULL)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, hd + 1});
        }
    }
    for (auto &x : m)
    {
        vector<int> temp = x.second;
        for (auto &t : temp)
        {
            v.push_back(t);
        }
    }
    return v;
}
void length(Node *root, int& maxi, int& mini, int curr)
{
    if (root == NULL)
    {
        return;
    }
    length(root->left, maxi, mini, curr - 1);
    mini = min(mini, curr);
    maxi = max(maxi, curr);
    length(root->right, maxi, mini, curr + 1);
}
int verticalWidth(Node* root)
{
    int maxi = 0, mini = 0;
    length(root, maxi, mini, 0);
    return (1 + abs(mini) + maxi);
}
int size(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
}
void mirror(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    swap(root->right, root->left);
    mirror(root->left);
    mirror(root->right);
}
void spiralTraversal(Node *root)
{
    if (root == NULL)
        return;
    stack <Node*> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *curr = s1.top();
            s1.pop();
            cout << curr->data << " ";
            if (curr->left != NULL)
            {
                s2.push(curr->left);
            }
            if (curr->right != NULL)
            {
                s2.push(curr->right);
            }
        }
        while (!s2.empty())
        {
            Node *curr = s2.top();
            s2.pop();
            cout << curr->data << " ";
            if (curr->right != NULL)
            {
                s1.push(curr->right);
            }
            if (curr->left != NULL)
            {
                s1.push(curr->left);
            }
        }
    }
}
Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        Node* newNode = new Node(key);
        return newNode;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right	= insert(root->right, key);
    }
    return root;
}
void inOrder(Node* root)
{
    if (root == NULL)
    {
        cout << "N" << " ";
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Node* root)
{
    if (root == NULL)
    {
        //cout << "N" << " ";
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root)
{
    if (root == NULL)
    {
        cout << "N" << " ";
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void levelOrder(Node* root)
{
    queue <Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
}
void levelOrderlinebyline(Node *root)
{
    if (root == NULL)
        return;
    queue <Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
            nodeCount--;
        }
        cout << endl;
    }
}
int findHeight(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lefth = findHeight(root->left);
    int righth = findHeight(root->right);

    return max(lefth, righth) + 1;
}
bool isCProperty(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
        sum += root->left->data;
    if (root->right != NULL)
        sum += root->right->data;
    if (sum == root->data && isCProperty(root->left) && isCProperty(root->right))
        return true;
    else
        return false;
}
void printGivenLevel(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
        cout << root->data << " ";
    printGivenLevel(root->left, k - 1);
    printGivenLevel(root->right, k - 1);
}
Node *FindMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *Delete(Node *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //Case 2: One child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else
        {
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
int floorValue(Node *root, int key)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    if (root->data == key)
    {
        return root->data;
    }
    if (root->data > key)
    {
        return floorValue(root->left, key);
    }
    int value = floorValue(root->right, key);
    return (value <= key) ? value : root->data;
}
int ceilValue(Node *root, int key)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key)
    {
        return root->data;
    }
    if (root->data < key)
    {
        return ceilValue(root->right, key);
    }
    int value = ceilValue(root->left, key);
    return (value >= key) ? value : root->data;
}
int main()
{
    FAST_IO;
    int x;
    Node *root = NULL;
    while (cin >> x)
    {
        root = insert(root, x);
    }
    levelOrderlinebyline(root);
    return 0;
}
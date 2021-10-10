#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x)
    // {
    //     this->val = x;
    //     this->left = nullptr;
    //     this->right = nullptr;
    // }
};

void inOrder(TreeNode *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

void preOrder(TreeNode *root)
{
    if (root != nullptr)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void distanceK(TreeNode *root, int K)
{
    if (root == nullptr)
    {
        return;
    }
    if (K == 0)
    {
        cout << root->val << " ";
        return;
    }
    distanceK(root->left, K - 1);
    distanceK(root->right, K - 1);
}

void levelOrder(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
}

void levelOrderlineByLine(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int curSize = q.size();
        for (int i = 0; i < curSize; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        cout << "\n";
    }
}

int getSize(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int maxInTree(TreeNode *root)
{
    if (root == nullptr)
        return -INF;
    return max(root->val, max(maxInTree(root->left), maxInTree(root->right)));
}

void leftViewRecursive(TreeNode *root, int level, int &maxLevel)
{
    if (root == nullptr)
        return;
    if (maxLevel < level)
    {
        cout << root->val << " ";
        maxLevel = level;
    }
    leftViewRecursive(root->left, level + 1, maxLevel);
    leftViewRecursive(root->right, level + 1, maxLevel);
}

void leftViewIterative(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (i == 0)
                cout << cur->val << " ";
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }
    }
}

bool isCSum(TreeNode *root)
{
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return true;
    int sum = 0;
    if (root->left != nullptr)
        sum += root->left->val;
    if (root->right != nullptr)
        sum += root->right->val;
    return (root->val == sum && isCSum(root->left) && isCSum(root->right));
}

int isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}

// Passing a reference (pointer to pointer) to the head and prev.
void binaryTreetoDLL(TreeNode *root, TreeNode *&head, TreeNode *&PREV)
{
    if (root == nullptr)
    {
        return;
    }
    binaryTreetoDLL(root->left, head, PREV);
    if (PREV == nullptr)
    {
        head = root;       // head gets initialized only one time.
    }
    else
    {
        root->left = PREV;
        PREV->right = root;
    }
    PREV = root;
    binaryTreetoDLL(root->right, head, PREV);
}

TreeNode *cTreeUtil(int pre[], unordered_map<int, int> &m, int is, int ie, int &preIndex)
{
    if (is > ie)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(pre[preIndex++]);
    int inIndex = m[root->val];
    root->left = cTreeUtil(pre, m, is, inIndex - 1, preIndex);
    root->right = cTreeUtil(pre, m, inIndex + 1, ie, preIndex);
    return root;
}

void cTreefromInAndPre()
{
    int n, preIndex = 0;
    cin >> n;
    int in[n], pre[n];
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        m.insert({in[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    TreeNode *root = cTreeUtil(pre, m, 0, n - 1, preIndex);
    inOrder(root);
}

void spiralTraversal(TreeNode *root)
{
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            TreeNode *curr = s1.top();
            s1.pop();
            cout << curr->val << " ";
            if (curr->left != nullptr)
                s2.push(curr->left);
            if (curr->right != nullptr)
                s2.push(curr->right);
        }
        while (!s2.empty())
        {
            TreeNode *curr = s2.top();
            s2.pop();
            cout << curr->val << " ";
            if (curr->right != nullptr)
                s1.push(curr->right);
            if (curr->left != nullptr)
                s1.push(curr->left);
        }
    }
}

int diameter(TreeNode *root, int &res)
{
    if (root == nullptr)
        return 0;
    int lh = diameter(root->left, res);
    int rh = diameter(root->right, res);
    res = max(res, 1 + lh + rh);
    return 1 + max(lh, rh);
}

TreeNode *lca(TreeNode *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == n1 || root->val == n2)
    {
        return root;
    }
    TreeNode *lca1 = lca(root->left, n1, n2);
    TreeNode *lca2 = lca(root->right, n1, n2);
    if (lca1 != nullptr && lca2 != nullptr)
    {
        return root;
    }
    if (lca1 != nullptr)
    {
        return lca1;
    }
    else
    {
        return lca2;
    }
}

int burnTime(TreeNode *root, int leaf, int &dist, int &res)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->val == leaf)
    {
        dist = 0;
        return 1;
    }
    int ldist = -1, rdist = -1;
    int lh = burnTime(root->left, leaf, ldist, res);
    int rh = burnTime(root->right, leaf, rdist, res);
    if (ldist != -1)
    {
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    else if (rdist != -1)
    {
        dist = rdist + 1;
        res = max(res, dist + lh);
    }
    return max(lh, rh) + 1;
}

int nodesInCompleteBTree(TreeNode *root)
{
    int left = 0, right = 0;
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        left++;
        curr = curr->left;
    }
    curr = root;
    while (curr != nullptr)
    {
        right++;
        curr = curr->right;
    }
    if (left == right)
    {
        return pow(2, left) - 1;
    }
    else
    {
        return 1 + nodesInCompleteBTree(root->left) + nodesInCompleteBTree(root->right);
    }
}

void serialize(TreeNode *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->val);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

TreeNode *deSerialize(vector<int> &arr, int &idx)
{
    if (arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    if (idx == (int)arr.size())
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(arr[idx++]);
    root->left = deSerialize(arr, idx);
    root->right = deSerialize(arr, idx);
    return root;
}

void iterativeInorderTraversal(TreeNode *root)
{
    stack<TreeNode*> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

void iterativePreorderTraversal(TreeNode *root)
{
    stack<TreeNode*> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            cout << curr->val << " ";
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}

void iterativePreorderTraversal2(TreeNode *root)
{
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *curr = s.top();
        s.pop();
        cout << curr->val << " ";
        if (curr->right != nullptr)
            s.push(curr->right);
        if (curr->left != nullptr)
            s.push(curr->left);
    }
}

// Space optimized
void iterativePreorderTraversal3(TreeNode *root)
{
    stack<TreeNode*> s;
    TreeNode *curr = root;
    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            cout << curr->val << " ";
            if (curr->right != nullptr)
            {
                s.push(curr->right);
            }
            curr = curr->left;
        }
        if (!s.empty())
        {
            curr = s.top();
            s.pop();
        }
    }
}

bool isFoldableHelper(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr))
    {
        return false;
    }
    return isFoldableHelper(left->left, right->right) && isFoldableHelper(left->right, right->left);
}
bool IsFoldable(TreeNode* root)
{
    if (root == nullptr)
        return true;
    return isFoldableHelper(root->left, root->right);
}

void mirror(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

TreeNode *createBST(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        TreeNode *newNode = new TreeNode(key);
        return newNode;
    }
    if (root->val == key)
    {
        return root;
    }
    else if (key > root->val)
    {
        root->right = createBST(root->right, key);
    }
    else
    {
        root->left = createBST(root->left, key);
    }
    return root;
}

TreeNode *findMin(TreeNode *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

TreeNode *findMax(TreeNode *root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            TreeNode *temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

int floor(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }
    if (root->val == x)
    {
        return root->val;
    }
    else if (root->val > x)
    {
        return floor(root->left, x);
    }
    int value = floor(root->right, x);
    return (value <= x) ? value : root->val;
}

int ceil(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }
    if (root->val == x)
    {
        return root->val;
    }
    else if (root->val < x)
    {
        return ceil(root->right, x);
    }
    int value = ceil(root->left, x);
    return (value >= x) ? value : root->val;
}

bool isValidBSTUtil(TreeNode *root, int mini, int maxi)
{
    if (root == nullptr)
    {
        return true;
    }
    int x = root->val;
    if (x < mini || x > maxi)
    {
        return false;
    }
    return (isValidBSTUtil(root->left, mini, x - 1)) &&
           (isValidBSTUtil(root->right, x + 1, maxi));
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTUtil(root, INT_MIN, INT_MAX);
}

void fixBSTUtil(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second)
{
    if (root == nullptr)
        return;
    fixBSTUtil(root->left, prev, first, second);
    if (prev != nullptr && prev->val > root->val)
    {
        if (first == nullptr)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    fixBSTUtil(root->right, prev, first, second);
}
void fixBSTwithTwoNodesSwapped(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
    fixBSTUtil(root, prev, first, second);
    swap(first->val, second->val);
}

void verticalSumInBSTUtil(TreeNode *root, int hd,  map<int, int> &m)
{
    if (root == nullptr)
        return;
    verticalSumInBSTUtil(root->left, hd - 1, m);
    m[hd] += root->val;
    verticalSumInBSTUtil(root->right, hd + 1, m);
}

void verticalSumInBST(TreeNode *root)
{
    if (root == nullptr)
        return;
    map<int, int> m;
    verticalSumInBSTUtil(root, 0, m);
    for (auto &x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
}

void verticalTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    map<int, vector<int>> m;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        m[hd].push_back(curr->val);
        if (curr->left != nullptr)
            q.push({curr->left, hd - 1});
        if (curr->right != nullptr)
            q.push({curr->right, hd + 1});
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}

void topView(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    map<int, int> m;
    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        if (!m.count(hd))
        {
            m.insert({hd, curr->val});
        }
        if (curr->left != nullptr)
            q.push({curr->left, hd - 1});
        if (curr->right != nullptr)
            q.push({curr->right, hd + 1});
    }
    for (auto &x : m)
    {
        cout << x.second << " ";
    }
}

void bottomView(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    map<int, int> m;
    while (!q.empty())
    {
        TreeNode *curr = q.front().first;
        int hd = q.front().second;
        q.pop();
        m[hd] = curr->val;
        if (curr->left != nullptr)
            q.push({curr->left, hd - 1});
        if (curr->right != nullptr)
            q.push({curr->right, hd + 1});
    }
    for (auto &x : m)
    {
        cout << x.second << " ";
    }
}

TreeNode *constructBstFromLevelOrder(vector<int> &arr)
{
    int n = arr.size();
    queue<pair<TreeNode*, pair<int, int>>> q;
    int i = 0;
    TreeNode *root = new TreeNode(arr[i++]);
    q.push({root, {INT_MIN, INT_MAX}});
    while (i < n)
    {
        TreeNode *curr = q.front().first;
        int minV = q.front().second.first;
        int maxV = q.front().second.second;
        q.pop();
        if (i < n && arr[i] < curr->val && arr[i] > minV)
        {
            curr->left = new TreeNode(arr[i++]);
            q.push({curr->left, {minV, curr->val}});
        }
        if (i < n && arr[i] > curr->val && arr[i] < maxV)
        {
            curr->right = new TreeNode(arr[i++]);
            q.push({curr->right, {curr->val, maxV}});
        }
    }
    return root;
}

//Function that constructs BST from its preorder traversal.
TreeNode *constructTree(int pre[], int size)
{
    stack<TreeNode *> s;
    TreeNode *root = new TreeNode(pre[0]);
    s.push(root);
    for (int i = 1; i < size; i++)
    {
        TreeNode *temp = NULL;
        while (!s.empty() && pre[i] > s.top()->val)
        {
            temp = s.top();
            s.pop();
        }
        if (temp != NULL)
        {
            temp->right = new TreeNode(pre[i]);
            s.push(temp->right);
        }
        else
        {
            s.top()->left = new TreeNode(pre[i]);
            s.push(s.top()->left);
        }
    }
    return root;
}

int main()
{
    SPEED;
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(60);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->right = new TreeNode(80);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(100);
    // int n, x;
    // TreeNode *root = nullptr;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> x;
    //     root = createBST(root, x);
    // }
    iterativePreorderTraversal2(root);
    return 0;
}

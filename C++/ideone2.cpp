#include <bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false), cin.tie(nullptr)
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct TreeNode
{
    int data;
    vector<TreeNode*> child;
    TreeNode(int key)
    {
        data = key;
    }
};

void levelOrder(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        for (int i = 1; i <= n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            for (int k = 0; k < (curr->child).size(); k++)
            {
                q.push(curr->child[k]);
            }
        }
        cout << endl;
    }
}

int main()
{
    SPEED;
    TreeNode *root = new TreeNode(10);
    (root->child).push_back(new TreeNode(2));
    (root->child).push_back(new TreeNode(34));
    (root->child).push_back(new TreeNode(56));
    (root->child).push_back(new TreeNode(100));
    (root->child[0]->child).push_back(new TreeNode(77));
    (root->child[0]->child).push_back(new TreeNode(88));
    (root->child[2]->child).push_back(new TreeNode(1));
    (root->child[3]->child).push_back(new TreeNode(7));
    (root->child[3]->child).push_back(new TreeNode(8));
    (root->child[3]->child).push_back(new TreeNode(9));
    levelOrder(root);
    return 0;
}
#include "afx.h"

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> result;
        queue<TreeNode *> q;
        if (root != nullptr)
        {
            q.push(root);
        }

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            result.push_back(p->val);
            if (p->left != nullptr)
            {
                q.push(p->left);
            }
            if (p->right != nullptr)
            {
                q.push(p->right);
            }
        }

        return result;
    }
};

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
        {
            return false;
        }

        queue<TreeNode *> q;
        if (A != nullptr)
        {
            q.push(A);
        }
        while (!q.empty())
        {
            auto p = q.front();
            if (isSubStructureInternal(p, B))
            {
                return true;
            }

            q.pop();
            if (p->left != nullptr)
            {
                q.push(p->left);
            }
            if (p->right != nullptr)
            {
                q.push(p->right);
            }
        }

        return false;
    }

private:
    bool isSubStructureInternal(TreeNode *a, TreeNode *b)
    {
        if (b == nullptr)
        {
            return true;
        }
        if (a == nullptr)
        {
            return false;
        }
        if (b->val != a->val)
        {
            return false;
        }
        return isSubStructureInternal(a->left, b->left) && isSubStructureInternal(a->right, b->right);
    }
};

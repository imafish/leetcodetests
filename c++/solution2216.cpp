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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTreeInternal(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

private:
    TreeNode *buildTreeInternal(vector<int>::iterator preorderBegin, vector<int>::iterator preorderEnd, vector<int>::iterator inorderBegin, vector<int>::iterator inorderEnd)
    {
        if (preorderBegin == preorderEnd)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(*preorderBegin);
        auto inorderMid = inorderBegin;
        while (*inorderMid != root->val)
        {
            inorderMid++;
        }

        preorderBegin++;
        auto preorderMid = preorderBegin + (inorderMid - inorderBegin);

        root->left = buildTreeInternal(preorderBegin, preorderMid, inorderBegin, inorderMid);
        root->right = buildTreeInternal(preorderMid, preorderEnd, inorderMid + 1, inorderEnd);

        return root;
    }
};

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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string result;
        queue<TreeNode *> q;
        q.push(root);
        unique_ptr<char[]> buffer = std::make_unique<char[]>(PTRSIZE * 3 + INTSIZE + 1);
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            sprintf(buffer.get(), "%p%p%p%d%c", (void *)p, (void *)p->left, (void *)p->right, p->val, SEPRATOR);
            result.append(buffer.get());
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        TreeNode *p = nullptr;
        TreeNode *root = nullptr;
        auto start = data.begin();
        auto end = data.end();

        while (p = getNode(start, end))
        {
            root = p;
        }

        return root;
    }

private:
    static constexpr char SEPRATOR = '|';
    static constexpr int INTSIZE = sizeof(int);
    static constexpr int PTRSIZE = sizeof(void *);

    TreeNode *getNode(string::iterator start, string::iterator end)
    {
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

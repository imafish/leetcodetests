#include "afx.h"
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> result;

        stack<pair<Node *, bool>> st;
        if (root != nullptr)
        {
            st.push(make_pair(root, true));
        }

        while (!st.empty())
        {
            auto &current = st.top();
            if (current.first->children.empty())
            {
                result.push_back(current.first->val);
                st.pop();
            }
            if (current.second)
            {
                for (auto i = current.first->children.rbegin(); i != current.first->children.rend(); i++)
                {
                    st.push({*i, true});
                }
                current.second = false;
            }
            else
            {
                st.pop();
                result.push_back(current.first->val);
            }
        }

        return result;
    }
};

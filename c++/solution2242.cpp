#include "afx.h"
using namespace std;

class Solution
{
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        return verifyPostorderInternal(postorder.rbegin(), postorder.rend());
    }

private:
    bool verifyPostorderInternal(reverse_iterator<vector<int>::iterator> begin, reverse_iterator<vector<int>::iterator> end)
    {
        if (begin == end || begin + 1 == end)
        {
            return true;
        }

        int root = *begin;
        begin++;
        auto leftBegin = begin;
        while (leftBegin != end && *leftBegin > root)
        {
            leftBegin++;
        }

        for (auto i = leftBegin; i != end; i++)
        {
            if (*i > root)
            {
                return false;
            }
        }

        return verifyPostorderInternal(begin, leftBegin) && verifyPostorderInternal(leftBegin, end);
    }
};

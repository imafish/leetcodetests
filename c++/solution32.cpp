#include "afx.h"
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int sz = s.length();
        int maxLen = 0;
        int j = 0;
        stack<int> openings;
        vector<int> f(sz, 0);

        for (int j = 0; j < sz; j++)
        {
            if (s[j] == '(')
            {
                openings.push(j);
                f[j] = 0;
            }
            else if (!openings.empty())
            {
                int i = openings.top();
                openings.pop();
                int len = j - i + 1;
                if (i == 0)
                {
                    f[j] = len;
                }
                else
                {
                    f[j] = len + f[i - 1];
                }
                if (maxLen < f[j])
                {
                    maxLen = f[j];
                }
            }
            else
            {
                f[j] = 0;
            }
        }

        return maxLen;
    }
};

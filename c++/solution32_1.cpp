#include "afx.h"
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int sz = s.length();
        int maxLen = 0;
        vector<int> dp(sz, 0);

        for (int i = 1; i < sz; i++)
        {
            if (s[i] == ')')
            {
                int len = 0;
                if (s[i - 1] == '(')
                {
                    if (i - 2 >= 0)
                    {
                        len = 2 + dp[i - 2];
                    }
                    else
                    {
                        len = 2;
                    }
                }
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    if (i - dp[i - 1] - 2 >= 0)
                    {
                        len = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
                    }
                    else
                    {
                        len = 2 + dp[i - 1];
                    }
                }
                if (maxLen < len)
                {
                    maxLen = len;
                }
                dp[i] = len;
            }
        }

        return maxLen;
    }
};

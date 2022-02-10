#include "afx.h"
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int sz = s.size();
        if (sz == 1)
        {
            return s;
        }
        else if (sz == 2)
        {
            if (s[0] == s[1])
            {
                return s;
            }
            else
            {
                return s.substr(0, 1);
            }
        }

        vector<vector<bool>> dp(sz, vector<bool>(sz));
        int maxI = 0;
        int maxJ = 0;
        int max = 0;

        for (int i = 0; i < sz; i++)
        {
            dp[i][i] = true;
        }

        for (int l = 2; l <= sz; l++)
        {
            for (int i = 0; i < sz - l + 1; i++)
            {
                int j = i + l - 1;
                if (j == i + 1)
                {
                    dp[i][j] = s[i] == s[j];
                }
                else if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && l > max)
                {
                    max = l;
                    maxI = i;
                    maxJ = j;
                }
            }
        }
        return s.substr(maxI, maxJ - maxI + 1);
    }
};

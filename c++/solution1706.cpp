#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int lastPos = dp[i - 1][j];
                if (lastPos == -1)
                {
                    dp[i][j] = -1;
                }
                else if ((grid[i - 1][lastPos] == 1 && (lastPos == n - 1 || grid[i - 1][lastPos + 1] == -1)) ||
                         (grid[i - 1][lastPos] == -1 && (lastPos == 0 || grid[i - 1][lastPos - 1] == 1)))
                {
                    dp[i][j] = -1;
                }
                else if (grid[i - 1][lastPos] == 1)
                {
                    dp[i][j] = lastPos + 1;
                }
                else
                {
                    dp[i][j] = lastPos - 1;
                }
            }
        }

        return dp[m];
    }
};

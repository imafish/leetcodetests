#include "afx.h"
using namespace std;

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        if (k == 0)
        {
            if (row >= 0 && row < n && column >= 0 && column < n)
            {
                return 1.0;
            }
            else
            {
                return 0.0;
            }
        }

        static constexpr int steps[8][2] = {
            {1, 2},
            {2, 1},
            {1, -2},
            {2, -1},
            {-1, -2},
            {-2, -1},
            {-1, 2},
            {-2, 1},
        };

        vector<vector<vector<double>>> dp(k, vector<vector<double>>(n + 1, vector<double>(n + 1, 0.0)));

        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                dp[0][x][y] = 1.0;
            }
        }

        for (int i = 1; i < k; i++)
        {
            for (int x = 0; x <= n; x++)
            {
                for (int y = 0; y <= n; y++)
                {
                    double p = 0.0;
                    for (int j = 0; j < 8; j++)
                    {
                        int nx = x + steps[j][0];
                        int ny = y + steps[j][1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            p += 0.125 * dp[i - 1][nx][ny];
                        }
                    }
                    dp[i][x][y] = p;
                }
            }
        }

        double result = 0.0;
        for (int i = 0; i < 8; i++)
        {
            int nx = row + steps[i][0];
            int ny = column + steps[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                result += 0.125 * dp[k - 1][nx][ny];
            }
        }
        return result;
    }
};

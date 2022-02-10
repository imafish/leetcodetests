#include "afx.h"
using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0)
        {
            return 0;
        }
        int m = grid[0].size();
        if (m == 0)
        {
            return 0;
        }

        int result[n][m];

        result[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            result[0][i] = grid[0][i] + result[0][i - 1];
        }
        for (int i = 1; i < n; i++)
        {
            result[i][0] = grid[i][0] + result[i - 1][0];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                result[i][j] = grid[i][j] + max(result[i - 1][j], result[i][j - 1]);
            }
        }

        return result[n - 1][m - 1];
    }
};

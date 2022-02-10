#include "afx.h"

using namespace std;

class Solution
{
public:
    Solution() : _directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}} {}

    int getMaximumGold(vector<vector<int>> &grid)
    {
        int max = 0;
        int current = 0;
        int m = grid.size();
        int n = grid[0].size();

        stack<array<int, 2>> future;
        function<void(int, int)> search = [&](int i, int j)
        {
            if (max < current)
            {
                max = current;
            }

            for (const auto &d : _directions)
            {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                {
                    if (grid[ni][nj] == 0)
                    {
                        continue;
                    }

                    int val = grid[ni][nj];
                    grid[ni][nj] = 0;
                    current += val;

                    search(ni, nj);

                    current -= val;
                    grid[ni][nj] = val;
                }
            }
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }

                int val = grid[i][j];
                current = val;
                grid[i][j] = 0;

                search(i, j);

                grid[i][j] = val;
            }
        }

        return max;
    }

private:
    int _directions[4][2];
};

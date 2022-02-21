#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> mins(m, INT_MAX);
        vector<int> maxes(n, INT_MIN);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                const int &val = matrix[i][j];
                if (mins[i] > val)
                {
                    mins[i] = val;
                }
                if (maxes[j] < val)
                {
                    maxes[j] = val;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            int row = mins[i];
            for (int j = 0; j < n; j++)
            {
                int col = maxes[j];
                if (row == col)
                {
                    result.push_back(row);
                    break;
                }
            }
        }

        return result;
    }
};

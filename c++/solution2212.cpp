#include "afx.h"
using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        if (n == 0)
        {
            return false;
        }

        int m = matrix[0].size();
        if (m == 0)
        {
            return false;
        }

        int i = 0;
        int j = m - 1;
        while (i < n && j >= 0)
        {
            const int &c = matrix[i][j];
            if (c < target)
            {
                i++;
            }
            else if (c > target)
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

    Solution s;
    auto result = s.findNumberIn2DArray(matrix, 20);
    cout << result << endl;

    return 0;
}

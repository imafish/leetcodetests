#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return vector<int>();
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = n * m;

        result = vector<int>(cnt);
        vector<vector<int>> history(n, vector<int>(m, 0));

        int x = 0;
        int y = -1;
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0;
        for (int i = 0; i < cnt; i++)
        {
            int nx = x + directions[directionIndex][0];
            int ny = y + directions[directionIndex][1];
            while (nx < 0 || nx >= n || ny < 0 || ny >= m || history[nx][ny] == 1)
            {
                directionIndex = (directionIndex + 1) % 4;
                nx = x + directions[directionIndex][0];
                ny = y + directions[directionIndex][1];
            }

            x = nx;
            y = ny;

            result[i] = matrix[x][y];
            history[x][y] = 1;
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.spiralOrder(matrix);
}

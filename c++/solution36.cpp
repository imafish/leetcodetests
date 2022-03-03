#include "afx.h"
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9] = {0};
        int cols[9] = {0};
        int blocks[9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int num = board[i][j] - '0' - 1;
                int idx = i / 3 * 3 + j / 3;

                if (((rows[i] >> (num)) & 1) ||
                    ((cols[j] >> (num)) & 1) ||
                    ((blocks[idx] >> (num)) & 1))
                {
                    return false;
                }
                rows[i] |= (1 << (num));
                cols[j] |= (1 << (num));
                blocks[idx] |= (1 << (num));
            }
        }
        return true;
    }
};

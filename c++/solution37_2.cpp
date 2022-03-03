#include "afx.h"
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        memset(_lines, 0, sizeof(_lines));
        memset(_cols, 0, sizeof(_cols));
        memset(_blocks, 0, sizeof(_blocks));

        vector<array<int, 2>> blanks;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    blanks.emplace_back(array{i, j});
                }
                else
                {
                    int val = board[i][j] - '0' - 1;
                    Set(i, j, val);
                }
            }
        }

        for (int i = 0; i < blanks.size(); i++)
        {
            auto [x, y] = blanks[i];
            int possibles = ((~_lines[x]) & (~_cols[y]) & (~_blocks[x / 3 * 3 + y / 3])) & 0x1ff;
            if (possibles == 0)
            {
                i -= 2;
                continue;
            }

            if (board[x][y] != '.')
            {
                int oldValue = board[x][y] - '0';
                int oldValueMask = (~(1 << oldValue - 1)) & 0x1ff;
                possibles &= oldValueMask;
            }
            int nextValue = GetSmallest1(possibles);
            if (nextValue == -1)
            {
                i -= 2;
                continue;
            }
            Set(x, y, nextValue);
            board[x][y] = '0' + (nextValue + 1);
        }
    }

private:
    int GetSmallest1(int mask)
    {
        int result = 0;
        for (; result < 9; result++, mask = mask >> 1)
        {
            if (mask & 1)
            {
                return result;
            }
        }
        return -1;
    }

    void Set(int x, int y, int val)
    {
        _lines[x] |= 1 << val;
        _cols[y] |= 1 << val;
        _blocks[x / 3 * 3 + y / 3] |= 1 << val;
    }

    int _lines[9];
    int _cols[9];
    int _blocks[9];
};

int main()
{
    vector<vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    s.solveSudoku(board);
}

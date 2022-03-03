#include "afx.h"
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        stack<array<int, 3>> history;

        array<array<int, 9>, 9> possibles;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                possibles[i][j] = (1 << 10) - 1;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int val = board[i][j] - '0';
                    for (int k = 0; k < 9; k++)
                    {
                        possibles[i][k] &= ~(1 << (val - 1));
                        possibles[k][j] &= ~(1 << (val - 1));
                        possibles[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3] &= ~(1 << (val - 1));
                    }
                }
            }
        }

        for (int i = 0, j = 0; i < 9 && j < 9; (i += (j + 1) / 9), (j = (j + 1) % 9))
        {
            if (board[i][j] != '.')
            {
                continue;
            }

            int val = 1;
            for (val = 1; val < 10; val++)
            {
                if ((possibles[i][j] >> (val - 1)) & 1)
                {
                    board[i][j] = '0' + val;
                    if (isValidSudoku(board))
                    {
                        history.push(array<int, 3>{i, j, val});
                        break;
                    }
                }
            }
            if (val < 10)
            {
                continue;
            }

            // no fit found in this block. go back.
            board[i][j] = '.';
            for (;;)
            {
                auto [hi, hj, hv] = history.top();
                history.pop();
                bool good = false;
                while (++hv < 10)
                {
                    if ((possibles[hi][hj] >> (hv - 1)) & 1)
                    {
                        board[hi][hj] = '0' + hv;
                        if (isValidSudoku(board))
                        {
                            good = true;
                            break;
                        }
                    }
                }
                if (good)
                {
                    history.push(array<int, 3>{hi, hj, hv});
                    i = hi;
                    j = hj;
                    break;
                }
                else
                {
                    board[hi][hj] = '.';
                }
            }
        }
    }

private:
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

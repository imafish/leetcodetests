#include "afx.h"
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int sz = dominoes.size();

        int previous = 0;
        string result(sz, '.');

        for (int i = 0; i < sz; i++)
        {
            if (dominoes[i] == '.')
            {
                result[i] = '.';
                continue;
            }
            else if (dominoes[i] == 'L')
            {
                for (int j = previous; j <= i; j++)
                {
                    result[j] = 'L';
                }
                previous = i;
            }
            else if (dominoes[i] == 'R')
            {
                int next = i + 1;
                for (; next < sz; next++)
                {
                    if (dominoes[next] != '.')
                    {
                        break;
                    }
                }
                if (next < sz)
                {
                    if (dominoes[next] == 'L')
                    {
                        if ((next - i) % 2 == 0)
                        {
                            int middle = i + (next - i) / 2;
                            for (int j = i; j < middle; j++)
                            {
                                result[j] = 'R';
                            }
                            result[middle] = '.';
                            for (int j = middle + 1; j <= next; j++)
                            {
                                result[j] = 'L';
                            }
                        }
                        else
                        {
                            int middle = i + (next - i) / 2;
                            for (int j = i; j <= middle; j++)
                            {
                                result[j] = 'R';
                            }
                            for (int j = middle + 1; j <= next; j++)
                            {
                                result[j] = 'L';
                            }
                        }
                        previous = next;
                        i = next;
                    }
                    else
                    {
                        for (int j = i; j < next; j++)
                        {
                            result[j] = 'R';
                        }
                        i = next - 1;
                    }
                }
                else
                {
                    for (int j = i; j < next; j++)
                    {
                        result[j] = 'R';
                    }
                    break;
                }
            }
        }
        return result;
    }
};

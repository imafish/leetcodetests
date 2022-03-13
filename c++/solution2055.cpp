#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        std::vector<int> result(queries.size());
        prepare(s);
        for (int i = 0; i < queries.size(); i++)
        {
            result[i] = findOne(queries[i]);
        }

        return result;
    }

private:
    int findOne(vector<int> &query)
    {
        int left = _data[query[0]][2];
        int right = _data[query[1]][1];
        if (left == -1 || right == -1 || left >= right)
        {
            return 0;
        }

        int total = _data[right][0] - _data[left][0];
        return total;
    }

    void prepare(const string &s)
    {
        _data.resize(s.length());
        int lastCandle = -1;
        int plateIndex = 0;
        int i = 0;
        for (; i < s.length(); i++)
        {
            if (s[i] == '|')
            {
                lastCandle = i;
                _data[i][0] = plateIndex;
                _data[i][1] = i;
            }
            else
            {
                _data[i][0] = plateIndex++;
                _data[i][1] = lastCandle;
            }
        }
        lastCandle = -1;
        for (i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '|')
            {
                lastCandle = i;
                _data[i][2] = i;
            }
            else
            {
                _data[i][2] = lastCandle;
            }
        }
    }

private:
    std::vector<std::array<int, 3>> _data;
};

#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int sz = security.size();
        vector<array<int, 2>> history(sz);
        history[0][0] = 0;
        history[sz - 1][1] = 0;

        for (int i = 1; i < sz; i++)
        {
            if (security[i] <= security[i - 1])
            {
                history[i][0] = history[i - 1][0] + 1;
            }
            else
            {
                history[i][0] = 0;
            }
        }

        for (int i = sz - 2; i >= 0; i--)
        {
            if (security[i] <= security[i + 1])
            {
                history[i][1] = history[i + 1][1] + 1;
            }
            else
            {
                history[i][1] = 0;
            }
        }

        vector<int> result;
        for (int i = 0; i < sz; i++)
        {
            if (history[i][0] >= time && history[i][1] >= time)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

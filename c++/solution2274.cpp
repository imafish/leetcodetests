#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> result;

        for (int i = target % 2 == 1 ? 2 : 3; i < target / 2; i++)
        {
            int a = (2 * target + i - i * i);
            int b = 2 * i;
            if (a < b)
            {
                break;
            }
            if (a % b == 0)
            {
                int start = a / b;
                vector<int> value;
                for (int j = 0; j < i; j++)
                {
                    value.push_back(start + j);
                }
                result.push_back(std::move(value));
            }
        }

        sort(result.begin(), result.end(), [](vector<int> &i, vector<int> &j) -> bool
             { return i[0] < j[0]; });

        return result;
    }
};

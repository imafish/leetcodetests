#include "afx.h"
using namespace std;

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> history;
        int total = 0;
        for (auto i : nums)
        {
            int &cnt = history[i];
            if (cnt == 0)
            {
                total += i;
            }
            else if (cnt == 1)
            {
                total -= i;
            }
            ++cnt;
        }
        return total;
    }
};

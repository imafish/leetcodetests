#include "afx.h"
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < 31; i++)
        {
            int bits = 0;
            int v = 1 << i;
            for (auto n : nums)
            {
                if ((n & v) > 0)
                {
                    bits++;
                }
            }
            if (bits % 3 > 0)
            {
                result += v;
            }
        }

        return result;
    }
};

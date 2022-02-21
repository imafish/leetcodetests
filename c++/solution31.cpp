#include "afx.h"
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int sz = nums.size();

        int i;
        for (i = sz - 2; i >= 0 && nums[i] >= nums[i + 1]; i--)
        {
        }

        if (i >= 0)
        {
            int j;
            for (j = sz - 1; j > i && nums[i] >= nums[j]; j--)
            {
            }

            if (j > i)
            {
                swap(nums[i], nums[j]);
            }
        }

        for (int k = i + 1, l = sz - 1; k < l; ++k, --l)
        {
            swap(nums[k], nums[l]);
        }
    }
};

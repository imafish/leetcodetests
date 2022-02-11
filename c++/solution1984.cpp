#include "afx.h"
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        int cnt = nums.size();
        std::sort(nums.begin(), nums.end());
        int result = INT_MAX;

        for (int i = 0; i < cnt - k + 1; i++)
        {
            int j = i + k - 1;
            if (result > (nums[j] - nums[i]))
            {
                result = nums[j] - nums[i];
            }
            while (i < cnt - 1 && nums[i] == nums[i + 1])
            {
                i++;
                continue;
            }
        }

        return result;
    }
};

#include "afx.h"
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int sz = nums.size();
        int begin = 0;
        int end = sz;
        while (true)
        {
            int mid = (begin + end) / 2;
            int other = -1;
            if (mid > begin && nums[mid - 1] == nums[mid])
            {
                other = mid - 1;
            }
            else if (mid < end - 1 && nums[mid] == nums[mid + 1])
            {
                other = mid + 1;
            }
            if (other == -1)
            {
                return nums[mid];
            }
            if (other > mid)
            {
                swap(other, mid);
            }
            if (other % 2 == 0)
            {
                begin = mid + 1;
            }
            else
            {
                end = other;
            }
        }
    }
};

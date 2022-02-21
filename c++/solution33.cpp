#include "afx.h"
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int pivot = findPivot(nums);
        if (pivot == 0)
        {
            return findIndex(nums, 0, nums.size(), target);
        }
        else if (target >= nums[0])
        {
            return findIndex(nums, 0, pivot, target);
        }
        else
        {
            return findIndex(nums, pivot, nums.size(), target);
        }
    }

private:
    int findPivot(vector<int> &nums)
    {
        int sz = nums.size();
        if (sz == 1)
        {
            return 0;
        }
        if (nums[0] < nums[sz - 1])
        {
            return 0;
        }
        int start = 0;
        int end = sz;
        while (start < end)
        {
            int pivot = (start + end) / 2;
            if (pivot < sz - 1 && pivot > 0 && nums[pivot] < nums[pivot + 1] && nums[pivot] < nums[pivot - 1])
            {
                return pivot;
            }
            if (pivot == 0 && nums[pivot] < nums[sz - 1])
            {
                return 0;
            }
            if (pivot == sz - 1 && nums[0] > nums[pivot] && nums[pivot] < nums[pivot - 1])
            {
                return pivot;
            }

            if (nums[pivot] > nums[0])
            {
                start = pivot + 1;
            }
            else if (nums[pivot] < nums[0])
            {
                end = pivot;
            }
        }
        return 0;
    }

    int findIndex(vector<int> &nums, int start, int end, int target)
    {
        while (start < end)
        {
            int pivot = (start + end) / 2;
            if (nums[pivot] == target)
            {
                return pivot;
            }
            else if (nums[pivot] < target)
            {
                start = pivot + 1;
            }
            else
            {
                end = pivot;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums{6, 7, 8, 1, 2, 3, 4, 5};
    s.search(nums, 6);
}

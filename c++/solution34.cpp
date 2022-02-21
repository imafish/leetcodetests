#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size();
        int m = -1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                m = mid;
                break;
            }
            else if (target < nums[mid])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        if (m == -1)
        {
            return {-1, -1};
        }

        int s1 = start;
        int e1 = end;
        int left;
        end = m;
        if (nums[0] == target)
        {
            left = 0;
        }
        else
        {
            while (true)
            {
                int mid = (start + end) / 2;
                if (nums[mid] == target && nums[mid - 1] != target)
                {
                    left = mid;
                    break;
                }
                else if (nums[mid] == target && nums[mid - 1] == target)
                {
                    end = mid;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }

        start = m;
        end = e1;
        int right;
        if (nums.back() == target)
        {
            right = nums.size() - 1;
        }
        else
        {
            while (true)
            {
                int mid = (start + end) / 2;
                if (nums[mid] == target && nums[mid + 1] != target)
                {
                    right = mid;
                    break;
                }
                else if (nums[mid] == target && nums[mid + 1] == target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid;
                }
            }
        }

        return vector<int>{left, right};
    }
};

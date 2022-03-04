#include "afx.h"
using namespace std;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long result = 0;
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            min = nums[i];
            max = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < min)
                {
                    min = nums[j];
                }
                if (nums[j] > max)
                {
                    max = nums[j];
                }
                result += max - min;
            }
        }
        return result;
    }
};

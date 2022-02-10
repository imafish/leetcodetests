#include "afx.h"
using namespace std;

class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int sz = nums.size();
        if (sz == 1)
        {
            return 0;
        }

        unordered_map<int, int> data;
        for (auto i : nums)
        {
            ++data[i];
        }

        int result = 0;
        for (auto &[i, v] : data)
        {
            if (data.find(i + k) != data.end())
            {
                result += v * data[i + k];
            }
        }

        return result;
    }
};

int main()
{
    vector<int> nums{9, 1, 6, 5, 2, 10, 1, 4, 3, 7};
    Solution s;
    int reuslt = s.countKDifference(nums, 8);
}

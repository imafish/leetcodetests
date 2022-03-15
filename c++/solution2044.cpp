#include "afx.h"
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int max = 0;
        for (const auto &i : nums)
        {
            max = max | i;
        }

        int i = 0;
        int current = 0;
        int count = 0;
        int sz = nums.size();
        vector<int> indexes;
        while (i < sz)
        {
            indexes.emplace_back(i);
            current = current | nums[i];
            if (current == max)
            {
                count += 1 << (sz - i - 1);

                int last = indexes.back();
                indexes.pop_back();
                if (last == sz - 1)
                {
                    if (indexes.empty())
                    {
                        break;
                    }
                    last = indexes.back();
                    indexes.pop_back();
                }
                i = last + 1;
                current = calculateCandidates(nums, indexes);
            }
            else if (i < sz - 1)
            {
                i++;
            }
            else if (indexes.size() == 1)
            {
                break;
            }
            else
            {
                indexes.pop_back();
                int last = indexes.back();
                indexes.pop_back();
                current = calculateCandidates(nums, indexes);
                i = last + 1;
            }
        }

        return count;
    }

private:
    int calculateCandidates(vector<int> &nums, vector<int> indexes)
    {
        int sum = 0;
        for (const auto &i : indexes)
        {
            sum = sum | nums[i];
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 1};
    int result = s.countMaxOrSubsets(nums);
    cout << result << endl;
}

#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result(nums.size() - k + 1);
        int sz = nums.size();
        if (sz == 0)
        {
            return vector<int>();
        }
        priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i], i});
        }
        result[0] = pq.top().first;
        for (int i = 1; i <= sz - k; i++)
        {
            int idx = i + k - 1;
            pq.push({nums[idx], idx});

            while (pq.top().second < i)
            {
                pq.pop();
            }

            result[i] = pq.top().first;
        }

        return result;
    }
};

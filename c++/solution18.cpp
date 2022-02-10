#include "afx.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        int sz = nums.size();
        if (sz < 4)
        {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int a = 0; a < sz - 3; a++)
        {
            int na = nums[a];
            if (a > 0 && nums[a - 1] == na)
            {
                continue;
            }
            if (int64_t(na) + nums[a + 1] + nums[a + 2] + nums[a + 3] > target)
            {
                break;
            }
            if (int64_t(na) + nums[sz - 1] + nums[sz - 2] + nums[sz - 3] < target)
            {
                continue;
            }

            for (int b = a + 1; b < sz - 2; b++)
            {
                int nb = nums[b];
                if (b > a + 1 && nums[b - 1] == nb)
                {
                    continue;
                }
                if (int64_t(na) + nb + nums[b + 1] + nums[b + 2] > target)
                {
                    break;
                }

                int c = b + 1;
                int d = sz - 1;
                while (c < d)
                {
                    int nc = nums[c];
                    int nd = nums[d];
                    int64_t sum = int64_t(na) + nb + nc + nd;
                    bool moveC = false;
                    bool moveD = false;
                    if (sum == target)
                    {
                        result.push_back({na, nb, nc, nd});
                        moveC = true;
                        moveD = true;
                    }
                    else if (sum < target)
                    {
                        moveC = true;
                    }
                    else
                    {
                        moveD = true;
                    }

                    if (moveC)
                    {
                        while (nums[++c] == nc && c < d)
                        {
                        }
                        if (c == d)
                        {
                            break;
                        }
                    }
                    if (moveD)
                    {
                        while (nums[--d] == nd && d > c)
                        {
                        }
                        if (d == c)
                        {
                            break;
                        }
                    }
                }
            }
        }

        return result;
    }
};

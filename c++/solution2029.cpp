#include <vector>
#include "solution.h"

using namespace std;

class Solution2029 : public Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        // calculate number of 1, 2, and 0
        int nums[3] = {0, 0, 0};

        for (int i : stones)
        {
            int index = i % 3;
            nums[index] = nums[index] + 1;
        }

        if (nums[0] % 2 == 0)
        {
            if (nums[1] > 0 && nums[2] > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return (nums[1] - nums[2] > 2) || (nums[2] - nums[1] > 2);
        }
    }
};

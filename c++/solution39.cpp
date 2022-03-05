#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;

        std::sort(candidates.begin(), candidates.end());
        vector<int> c{0};
        int currentTotal = candidates[0];

        while (!c.empty())
        {
            if (currentTotal == target)
            {
                vector<int> r(c.size());
                for (int i = 0; i < c.size(); i++)
                {
                    r[i] = candidates[c[i]];
                }
                result.push_back(std::move(r));
            }

            if (currentTotal >= target)
            {
                if (c.size() == 1)
                {
                    break;
                }
                currentTotal -= candidates[c.back()];
                c.pop_back();

                int lastPos;
                while (!c.empty() && (lastPos = c.back()) == candidates.size() - 1)
                {
                    currentTotal -= candidates[lastPos];
                    c.pop_back();
                }
                if (c.empty())
                {
                    break;
                }
                c[c.size() - 1] += 1;
                currentTotal += candidates[c.back()] - candidates[c.back() - 1];
            }
            else
            {
                c.emplace_back(c.back());
                currentTotal += candidates[c.back()];
            }
        }
        return result;
    }
};

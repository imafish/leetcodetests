#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        int sz = candidates.size();
        int total = candidates[0];
        vector<int> c{0};
        while (!c.empty())
        {
            if (total == target)
            {
                vector<int> r(c.size());
                for (int i = 0; i < c.size(); i++)
                {
                    r[i] = candidates[c[i]];
                }
                result.push_back(std::move(r));
            }
            bool advance = false;
            if (total >= target)
            {
                advance = true;
            }
            else if (c.back() == sz - 1)
            {
                advance = true;
            }

            if (advance)
            {
                total -= candidates[c.back()];
                c.pop_back();
                while (!c.empty())
                {
                    int i = c.back();
                    int j = c.back() + 1;
                    while (j < sz && candidates[j] == candidates[i])
                    {
                        j++;
                    }
                    if (j < sz)
                    {
                        total += candidates[j] - candidates[i];
                        c[c.size() - 1] = j;
                        break;
                    }
                    else
                    {
                        total -= candidates[i];
                        c.pop_back();
                    }
                }
            }
            else
            {
                c.push_back(c.back() + 1);
                total += candidates[c.back()];
            }
        }
        return result;
    }
};

int main()
{
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    Solution s;
    auto result = s.combinationSum2(candidates, 8);
    for (auto i : result)
    {
        std::cout << "[";
        for (auto j : i)
        {
            std::cout << j << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

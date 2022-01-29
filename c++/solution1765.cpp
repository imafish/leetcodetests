#include "afx.h"

using namespace std;

class Solution1765
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int iSize = isWater.size();
        int jSize = isWater.front().size();
        std::vector<std::vector<int>> height(iSize, std::vector<int>(jSize, INT_MAX));
        std::queue<std::array<int, 2>> q;

        // first fill all water blocks
        for (int i = 0; i < iSize; i++)
        {
            for (int j = 0; j < jSize; j++)
            {
                if (isWater[i][j])
                {
                    height[i][j] = 0;
                    q.push(std::array<int, 2>{i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto current = q.front();
            q.pop();
            int i = current[0];
            int j = current[1];
            int value = height[i][j] + 1;
            if (i > 0 && height[i - 1][j] == INT_MAX)
            {
                height[i - 1][j] = value;
                q.push(std::array<int, 2>{i - 1, j});
            }
            if (i < iSize - 1 && height[i + 1][j] == INT_MAX)
            {
                height[i + 1][j] = value;
                q.push(std::array<int, 2>{i + 1, j});
            }
            if (j > 0 && height[i][j - 1] == INT_MAX)
            {
                height[i][j - 1] = value;
                q.push(std::array<int, 2>{i, j - 1});
            }
            if (j < jSize - 1 && height[i][j + 1] == INT_MAX)
            {
                height[i][j + 1] = value;
                q.push(std::array<int, 2>{i, j + 1});
            }
        }

        return height;
    }
};

void print(const std::vector<std::vector<int>> &isWater, const std::vector<std::vector<int>> &result, int i)
{
    std::cout << "-------CASE #" << i << "-------" << std::endl;
    for (const auto &i : isWater)
    {
        for (const auto &j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "------- RESULT -------" << std::endl;
    for (const auto &i : result)
    {
        for (const auto &j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::pair<std::vector<std::vector<int>>, int>> testcases = {
        {{{0, 1}, {0, 0}}, 2},
        {{{1, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 0}, {1, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 1}, {1, 1, 0, 1, 0, 1}}, 1},
        {{{0, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0}}, 5}};

    Solution1765 s;
    for (int i = 0; i < testcases.size(); i++)
    {
        auto &tc = testcases[i];
        auto result = s.highestPeak(tc.first);
        print(tc.first, result, i + 1);
    }
}

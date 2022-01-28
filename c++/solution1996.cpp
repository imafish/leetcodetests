#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

class Solution1996
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        std::sort(properties.begin(), properties.end(), [](const vector<int> &l, const vector<int> &r)
                  { return l[0] == r[0] ? (l[1] < r[1]) : (l[0] > r[0]); });

        int maxDef = 0;
        int cnt = 0;
        for (const auto &p : properties)
        {
            if (p[1] > maxDef)
            {
                cnt++;
            }
            else
            {
                maxDef = p[1];
            }
        }

        return cnt;
    }
};

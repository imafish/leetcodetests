#include "afx.h"
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_map<int, int> edgeCounts;
        for (auto &e : edges)
        {
            edgeCounts[e[0]]++;
            edgeCounts[e[1]]++;
        }
        for (auto &p : edgeCounts)
        {
            if (p.second == edges.size())
            {
                return p.first;
            }
        }
        return -1;
    }
};

#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        vector<int> result(queries.size());
        int sz = queries.size();

        auto hashFunc = [](const pair<int, int> &p) -> size_t
        {
            return hash<int>()(p.first + p.second);
        };

        unordered_set<pair<int, int>, decltype(hashFunc)> lMap(0, hashFunc);
        unordered_map<int, int> cols, rows, line1, line2;

        for (auto &lamp : lamps)
        {
            if (lMap.find({lamp[0], lamp[1]}) == lMap.end())
            {
                lMap.insert({lamp[0], lamp[1]});
                rows[lamp[0]]++;
                cols[lamp[1]]++;
                line1[lamp[0] + lamp[1]]++;
                line2[lamp[0] - lamp[1]]++;
            }
        }
        for (int i = 0; i < sz; i++)
        {
            int row = queries[i][0];
            int col = queries[i][1];
            if (rows.find(row) != rows.end() && rows[row] > 0)
            {
                result[i] = 1;
            }
            else if (cols.find(col) != cols.end() && cols[col] > 0)
            {
                result[i] = 1;
            }
            else if (line1.find(col + row) != line1.end() && line1[col + row] > 0)
            {
                result[i] = 1;
            }
            else if (line2.find(row - col) != line2.end() && line2[row - col] > 0)
            {
                result[i] = 1;
            }

            for (int x = row - 1; x <= row + 1; x++)
            {
                for (int y = col - 1; y <= col + 1; y++)
                {
                    if (x < 0 || y < 0 || x >= n || y >= n || lMap.find({x, y}) == lMap.end())
                    {
                        continue;
                    }
                    lMap.erase({x, y});
                    rows[x]--;
                    cols[y]--;
                    line1[x + y]--;
                    line2[x - y]--;
                }
            }
        }
        return result;
    }
};

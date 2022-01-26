/*
https://leetcode-cn.com/problems/second-minimum-time-to-reach-destination/
*/

#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Solution2045
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> graph(n + 1);
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> path(n + 1, vector<int>(2, INT_MAX));
        path[1][0] = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (path[n][1] == INT_MAX)
        {
            auto [cur, len] = q.front();
            q.pop();
            for (auto next : graph[cur])
            {
                if (len + 1 < path[next][0])
                {
                    path[next][0] = len + 1;
                    q.push({next, len + 1});
                }
                else if (len + 1 > path[next][0] && len + 1 < path[next][1])
                {
                    path[next][1] = len + 1;
                    q.push({next, len + 1});
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < path[n][1]; i++)
        {
            if (ret % (2 * change) >= change)
            {
                ret = ret + (2 * change - ret % (2 * change));
            }
            ret = ret + time;
        }
        return ret;
    }
};

#include "afx.h"
using namespace std;

class Solution
{
public:
    int checkWays(vector<vector<int>> &pairs)
    {
        // adj.size() => number of nodes.
        // adj[i].size() => degree of node[i];
        unordered_map<int, unordered_set<int>> adj;
        for (auto &p : pairs)
        {
            adj[p[0]].emplace(p[1]);
            adj[p[1]].emplace(p[0]);
        }

        // find root node
        int root = -1;
        for (auto &[k, v] : adj)
        {
            if (v.size() == adj.size() - 1)
            {
                root = k;
                break;
            }
        }
        if (root == -1)
        {
            return 0;
        }

        int result = 1;
        for (auto &[k, v] : adj)
        {
            if (k == root)
            {
                continue;
            }

            int parent = -1;
            int parentDegree = INT_MAX;
            // current node's parent is the node with smallest degree whose degree is larger than node.
            for (auto &p : v)
            {
                if (parent == k)
                {
                    continue;
                }
                auto &parentAdj = adj[p];
                if (parentAdj.size() >= v.size() && parentAdj.size() < parentDegree)
                {
                    parent = p;
                    parentDegree = parentAdj.size();
                }
            }
            if (parent == -1)
            {
                return 0;
            }

            // parent's subnode set must be larger or equal of current node's
            for (auto value : v)
            {
                if (value == parent)
                {
                    continue;
                }
                if (adj[parent].find(value) == adj[parent].end())
                {
                    return 0;
                }
            }
            if (adj[parent].size() == v.size())
            {
                result = 2;
            }
        }

        return result;
    }
};

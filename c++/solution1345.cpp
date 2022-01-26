#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int len = arr.size();

        if (len == 0 || len == 1)
        {
            return 0;
        }

        int expectedIndex = len - 1;
        int step = 0;

        unordered_map<int, vector<int>> positionMap;
        for (int i = 0; i < len; i++)
        {
            positionMap[arr[i]].push_back(i);
        }

        vector<int> currentLayer{expectedIndex};
        unordered_set<int> history{expectedIndex};

        for (;;)
        {
            vector<int> nextLayer;
            step++;
            for (int i : currentLayer)
            {
                // add it's neighbors to next layer.
                int leftIndex = i - 1;
                if (leftIndex == 0)
                {
                    return step;
                }
                if (history.find(leftIndex) == history.end())
                {
                    history.insert(leftIndex);
                    nextLayer.push_back(leftIndex);
                }

                int rightIndex = i + 1;
                if (rightIndex < len)
                {
                    if (history.find(rightIndex) == history.end())
                    {
                        history.insert(rightIndex);
                        nextLayer.push_back(rightIndex);
                    }
                }

                for (int sameValueIndex : positionMap[arr[i]])
                {
                    if (i == sameValueIndex)
                    {
                        continue;
                    }
                    if (sameValueIndex == 0)
                    {
                        return step;
                    }
                    if (history.find(sameValueIndex) == history.end())
                    {
                        history.insert(sameValueIndex);
                        nextLayer.push_back(sameValueIndex);
                    }
                }
            }

            currentLayer = std::move(nextLayer);
        }

        return len - 1;
    }
};

int main()
{
    vector<int> input{100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    Solution s;
    int result = s.minJumps(input);

    cout << result << endl;
}

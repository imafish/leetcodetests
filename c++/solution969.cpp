#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> result;
        int sz = arr.size();
        int pos = 0;
        for (int i = 0; i < sz; i++)
        {
            if (arr[i] == sz)
            {
                pos = i;
                break;
            }
        }

        for (int i = sz; i > 0; i--)
        {
            if (pos != i - 1)
            {
                result.push_back(pos + 1);
                result.push_back(i);

                pancakeReorder(arr, pos + 1);
                pos = pancakeReorder(arr, i);
            }
            else
            {
                // find pos
                for (int j = 0; j < i - 1; j++)
                {
                    if (arr[j] == i - 1)
                    {
                        pos = j;
                        break;
                    }
                }
            }
        }

        return result;
    }

private:
    int pancakeReorder(vector<int> &arr, int k)
    {
        int pos;
        for (int i = 0; i < k / 2; i++)
        {
            swap(arr[i], arr[k - 1 - i]);
            if (arr[i] == k - 1)
            {
                pos = i;
            }
            else if (arr[k - 1 - i] == k - 1)
            {
                pos = k - 1 - i;
            }
        }
        return pos;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3, 2, 4, 1};
    s.pancakeSort(arr);
}

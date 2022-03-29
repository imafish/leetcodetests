#include "afx.h"

using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int remaining = 0;
        for (int i : rolls)
        {
            remaining += i;
        }
        int m = rolls.size();
        int total = mean * (m + n);
        int missing = total - remaining;

        if (missing < n || missing > 6 * n)
        {
            return vector<int>();
        }

        int average = missing / n;
        int remainder = missing % n;
        vector<int> result(n, average);
        int more = average + 1;
        for (int i = 0; i < remainder; i++)
        {
            result[i] = more;
        }
        return result;
    }
};

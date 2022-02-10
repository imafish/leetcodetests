#include "afx.h"
using namespace std;

class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        else if (n == 3)
        {
            return 2;
        }
        else if (n == 4)
        {
            return 4;
        }
        vector<int> f(n + 1);
        f[1] = 1;
        f[2] = 2;
        f[3] = 3;
        f[4] = 4;

        for (int i = 4; i <= n; i++)
        {
            int max = 1;
            for (int j = 1; j < i; j++)
            {
                int current = f[j] * f[i - j];
                if (max < current)
                {
                    max = current;
                }
            }
            f[i] = max;
        }

        return f[n];
    }
};

#include "afx.h"

class Solution
{
public:
    int numWays(int n)
    {
        if (n == 1 || n == 0)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }

        int a = 1;
        int b = 2;
        while (n-- > 2)
        {
            int c = (a + b) % 1000000007;
            a = b;
            b = c;
        }

        return b;
    }
};

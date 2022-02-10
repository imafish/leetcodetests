#include "afx.h"

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        int64_t n64(n);
        if (n64 < 0)
        {
            n64 = -n64;
            x = 1 / x;
        }

        double expo = x;
        double result = 1.0;
        while (n64 > 0)
        {
            if (n64 & 0x1)
            {
                result = result * expo;
            }
            n64 = n64 >> 1;
            expo = expo * expo;
        }

        return result;
    }
};

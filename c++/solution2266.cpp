#include "afx.h"
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        std::vector<int> data(n);
        data[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        for (int i = 1; i < n; i++)
        {
            int x2 = data[i2] * 2;
            int x3 = data[i3] * 3;
            int x5 = data[i5] * 5;
            while (x2 <= data[i - 1])
            {
                i2++;
                x2 = data[i2] * 2;
            }
            while (x3 <= data[i - 1])
            {
                i3++;
                x3 = data[i3] * 3;
            }
            while (x5 <= data[i - 1])
            {
                i5++;
                x5 = data[i5] * 5;
            }

            int minNum = min(min(x2, x3), x5);
            if (minNum == x2)
            {
                i2++;
            }
            else if (minNum == x3)
            {
                i3++;
            }
            else
            {
                i5++;
            }
            data[i] = minNum;
        }

        return data[n - 1];
    }
};

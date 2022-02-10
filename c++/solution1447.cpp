#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> result;
        char buf[8];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (coprime(j, i))
                {
                    sprintf(buf, "%d/%d", j, i);
                    result.emplace_back(buf);
                }
            }
        }
        return result;
    }

private:
    bool coprime(int a, int b)
    {
        while (b > 0)
        {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a == 1;
    }
};

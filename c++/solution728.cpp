#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;

        for (int i = left; i <= right; i++)
        {
            if (isSelfDividingNumber(i))
            {
                result.emplace_back(i);
            }
        }

        return result;
    }

private:
    bool isSelfDividingNumber(int n)
    {
        bool result = true;
        int current = n;
        while (current > 0)
        {
            int div = current % 10;
            if (div == 0 || n % div != 0)
            {
                return false;
            }
            current = current / 10;
        }
        return true;
    }
};

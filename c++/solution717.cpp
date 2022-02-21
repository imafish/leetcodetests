#include "afx.h"
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int sz = bits.size();
        if (sz == 1)
        {
            return true;
        }
        if (bits[sz - 2] == 0)
        {
            return true;
        }

        bool result = true;
        int i = 0;
        while (i < sz - 1)
        {
            if (bits[i] == 1)
            {
                i += 2;
            }
            else
            {
                i += 1;
            }
        }

        return i == sz - 1;
    }
};

#include <string>
#include "solution.h"
using namespace std;

class Solution1332 : public Solution
{
public:
    virtual bool run() override
    {
        return true;
    }

    int removePalindromeSub(string s)
    {
        int len = s.length();
        if (len == 0)
        {
            return 0;
        }

        for (int i = 0; i < len - 1; i++, len--)
        {
            if (s[i] != s[len - 1])
            {
                return 2;
            }
        }
        return 1;
    }
};

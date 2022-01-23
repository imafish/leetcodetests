#include "solution.h"

class Solution9 : public Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int j = 0;
        int numbers[10];
        while (x > 0)
        {
            numbers[j++] = x % 10;
            x = x / 10;
        }
        j--;

        int i = 0;
        while (i > j)
        {
            if (numbers[i++] != numbers[j--])
            {
                return false;
            }
        }
        return true;
    }
};

#include "afx.h"
using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }

        bool isNegative = num < 0;
        if (isNegative)
        {
            num = -num;
        }

        string str;
        while (num > 0)
        {
            str += ('0' + num % 7);
            num /= 7;
        }

        string result;
        if (isNegative)
        {
            result += '-';
        }
        for (int i = str.length() - 1; i >= 0; i--)
        {
            result += str[i];
        }
        return result;
    }
};

#include "afx.h"
using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z')))
            {
                l++;
            }
            else if (!((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z')))
            {
                r--;
            }
            else
            {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }

        return s;
    }
};

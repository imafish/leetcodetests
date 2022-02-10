#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> result;
        sort(s.begin(), s.end());
        result.push_back(s);
        while (next(s))
        {
            result.push_back(s);
        }

        return result;
    }

private:
    bool next(string &s)
    {
        int sz = s.size();
        int i = sz - 2;
        for (; i >= 0; i--)
        {
            if (s[i] < s[i + 1])
            {
                break;
            }
        }
        if (i < 0)
        {
            return false;
        }

        int j = sz - 1;
        while (j > i && s[i] <= s[j])
        {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + 1 + i, s.end());
        return true;
    }
};

#include "afx.h"
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int cnt[26] = {0};

        for (int i = 0; i < text.size(); i++)
        {
            ++cnt[text[i] - 'a'];
        }

        int b = cnt[1];
        int a = cnt[0];
        int l = cnt['l' - 'a'] / 2;
        int o = cnt['o' - 'a'] / 2;
        int n = cnt['n' - 'a'];

        return min(b, min(a, min(l, min(o, n))));
    }
};

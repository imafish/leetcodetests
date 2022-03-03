#include "afx.h"
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";
        for (int i = 1; i < n; i++)
        {
            result = sayOne(result);
        }

        return result;
    }

private:
    string sayOne(const string &s)
    {
        string result;

        char last = '\0';
        int cnt = 0;
        for (char c : s)
        {
            if (c != last)
            {
                if (cnt > 0)
                {
                    result += to_string(cnt * 10 + last - '0');
                }

                cnt = 1;
                last = c;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt > 0)
        {
            result += to_string(cnt * 10 + last - '0');
        }

        return result;
    }
};

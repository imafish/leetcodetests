#include "afx.h"
using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string result;
        vector<std::pair<int, char>> data{{a, 'a'}, {b, 'b'}, {c, 'c'}};

        bool going = true;
        while (going)
        {
            sort(data.begin(), data.end(), [](auto &l, auto &r) -> bool
                 { return l.first > r.first; });

            going = false;
            for (auto &[cnt, ch] : data)
            {
                if (cnt == 0)
                {
                    continue;
                }
                int len = result.length();
                if (len >= 2 && result[len - 1] == ch && result[len - 2] == ch)
                {
                    continue;
                }
                going = true;
                cnt--;
                result.push_back(ch);
                break;
            }
        }

        return result;
    }
};

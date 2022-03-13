#include "afx.h"
using namespace std;

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        /*
        state:
        0: end of byte sequence;
        >0: in byte sequence, state = bytes remaining
        */
        int state = 0;
        int result = true;
        for (auto &i : data)
        {
            if (state == 0)
            {
                if ((i & 0xF8) == 0xF0)
                {
                    state = 3;
                }
                else if ((i & 0xF0) == 0xE0)
                {
                    state = 2;
                }
                else if ((i & 0xE0) == 0xC0)
                {
                    state = 1;
                }
                else if ((i & 0x80) == 0)
                {
                    state = 0;
                }
                else
                {
                    result = false;
                    break;
                }
            }
            else if ((i & 0xC0) == 0x80)
            {
                state--;
            }
            else
            {
                result = false;
                break;
            }
        }
        if (state > 0)
        {
            result = false;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> data = {197, 130, 1};
    s.validUtf8(data);

    return 0;
}

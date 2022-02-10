#include "afx.h"
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int sz = pushed.size();
        stack<int> st;

        int pushIndex = -1;
        for (auto item : popped)
        {
            if (!st.empty() && st.top() == item)
            {
                st.pop();
            }
            else
            {
                pushIndex++;
                for (; pushIndex < sz && pushed[pushIndex] != item; pushIndex++)
                {
                    st.push(pushed[pushIndex]);
                }
                if (pushIndex == sz)
                {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool validateStackSequences2(vector<int> &pushed, vector<int> &popped)
    {
        int sz = pushed.size();
        int stackIndex = -1;
        for (auto item : popped)
        {
            int nextPos = stackIndex + 1;
            for (; nextPos < sz && pushed[nextPos] != item; nextPos++)
            {
            }

            if (nextPos == sz)
            {
                nextPos = stackIndex - 1;
                for (; nextPos >= 0 && pushed[nextPos] == -1; nextPos--)
                {
                }
                if (nextPos < 0 || pushed[nextPos] != item)
                {
                    return false;
                }
            }
            pushed[nextPos] = -1;
            stackIndex = nextPos;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 5, 3, 2, 1};
    s.validateStackSequences(pushed, popped);
}

#include <string>
#include <vector>
#include <deque>

#include "solution.h"

using namespace std;

class Solution10 : public Solution
{
public:
    bool isMatch(string s, string p)
    {
        auto tokens = analysis(p);

        auto b = s.begin();
        auto e = s.end();
        auto tb = tokens.begin();
        auto te = tokens.end();

        return isMatchInternal(b, e, tb, te);
    }

private:
    bool isMatchInternal(string::iterator b, string::iterator e, deque<string>::iterator tb, deque<string>::iterator te)
    {
    }

    deque<string> analysis(const string &p)
    {
        deque<string> tokens;
        for (auto i = p.begin(); i != p.end(); i++)
        {
            if (*i == '*')
            {
                if (tokens.size() == 0)
                {
                    throw "argument error: leading '*' is not allowed.";
                }
                string lastToken = tokens.back();
                if (*lastToken.rbegin() == '*')
                {
                    throw "argument error: successive '*' is not allowed.";
                }

                tokens.back() = lastToken + '*';
            }
            else
            {
                tokens.push_back(string(1, *i));
            }
        }

        return tokens;
    }
};

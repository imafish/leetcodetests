#include <string>
#include <vector>
#include <deque>
#include <list>
#include <assert.h>

#include "solution.h"

using namespace std;

class Solution10 : public Solution
{
public:
    bool isMatch(string s, string p)
    {
        auto tokens = analysis(p);
        int tokenSize = tokens.size();

        auto begin = s.begin();
        auto end = s.end();

        int i = 0;
        while (i < tokenSize)
        {
            TokenState &t = tokens[i];
            bool matching = matchToken(begin, end, &t);
            bool rollback = !matching;

            if (matching)
            {
                if (t.matchEnd == end && i == tokenSize - 1)
                {
                    return true;
                }
                else
                {
                    begin = t.matchEnd;
                }
            }

            if (rollback)
            {
                bool rollbackSuccessful = false;
                while (i >= 0)
                {
                    TokenState &toRollback = tokens[i];
                    if (toRollback.isVariableWidth)
                    {
                        if (toRollback.matchEnd > toRollback.matchBegin)
                        {
                            toRollback.matchEnd--;
                            begin = toRollback.matchEnd;
                            i++;
                            rollbackSuccessful = true;
                            break;
                        }
                        else
                        {
                            i--;
                        }
                    }
                    else
                    {
                        i--;
                    }
                }
                if (!rollbackSuccessful)
                {
                    return false;
                }
            }
            else
            {
                i++;
            }
        }

        return false;
    }

private:
    struct TokenState
    {
        TokenState() : isVariableWidth(false) {}
        TokenState(const std::string &t) : token(t), isVariableWidth(false) {}
        TokenState(const std::string &t, bool ivw) : token(t), isVariableWidth(ivw) {}

        std::string token;
        bool isVariableWidth;

        string::iterator matchBegin;
        string::iterator matchEnd;
        string::iterator matchMax;
        string::iterator matchMin;
    };

    bool matchToken(string::iterator begin, string::iterator end, TokenState *token)
    {
        if (token->isVariableWidth)
        {
            char x = token->token[0];
            if (x == '.')
            {
                token->matchBegin = begin;
                token->matchEnd = end;
                token->matchMin = begin;
                token->matchMax = end;
                return true;
            }
            else
            {
                token->matchBegin = begin;
                token->matchMin = begin;

                auto matchMax = begin;
                while (matchMax != end && *matchMax == x)
                {
                    matchMax++;
                };
                token->matchMax = matchMax;
                token->matchEnd = matchMax;
                return true;
            }
        }
        else
        {
            if (token->token.length() > (end - begin))
            {
                return false;
            }

            auto i = begin;
            auto ti = token->token.begin();
            auto tEnd = token->token.end();
            while (ti != tEnd)
            {
                if (*ti == '.' || *ti == *i)
                {
                    ti++;
                    i++;
                    continue;
                }
                else
                {
                    return false;
                }
            }

            token->matchBegin = begin;
            token->matchEnd = i;
            token->matchMin = i;
            token->matchMax = i;
            return true;
        }
    }

    deque<TokenState> analysis(const string &p)
    {
        deque<TokenState> tokens;
        string current;
        for (auto i = p.begin(); i != p.end(); i++)
        {
            if (*i == '*')
            {
                if (current.empty())
                {
                    throw "'*' must follow another character.";
                }
                if (current.length() == 1)
                {
                    current += *i;
                    tokens.emplace_back(current, true);
                    current.clear();
                }
                else
                {
                    // split token into two
                    string t1 = current.substr(0, current.length() - 1);
                    string t2 = current.substr(current.length() - 1) + *i;
                    tokens.emplace_back(t1);
                    tokens.emplace_back(t2, true);
                }
                current.clear();
            }
            else
            {
                current = current + *i;
            }
        }
        if (!current.empty())
        {
            tokens.emplace_back(current);
        }

        return tokens;
    }

public:
    struct TestCase
    {
        TestCase(const string &s, const string &p, bool e) : str(s), pattern(p), expected(e) {}
        string str;
        string pattern;
        bool expected;
    };

    virtual bool run() override
    {
        list<TestCase> testcases{
            {"a", "ab*", true},
            {"mississippi", "mis*is*p*.", false},
            {"aa", "a", false},
            {"aa", "a*", true},
            {"ab", ".*", true},
            {"aab", "c*a*b", true}};

        bool good = true;
        for (auto &tc : testcases)
        {
            bool actual = isMatch(tc.str, tc.pattern);
            printf("%s: `%s`, `%s`: expected: %d, actual: %d\n", actual == tc.expected ? "SUCCESS" : "FAIL   ", tc.str.c_str(), tc.pattern.c_str(), tc.expected, actual);
            if (actual != tc.expected)
            {
                good = false;
            }
        }

        return good;
    }
};

int main()
{
    Solution10 s;
    s.run();

    return 0;
}

#include "afx.h"
using namespace std;

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        std::array<int64_t, 5> candidates = getCandidates(n);
        string result = pickCandidate(candidates, n);
        return result;
    }

private:
    std::array<int64_t, 5> getCandidates(const string &n)
    {
        std::array<int64_t, 5> result;
        int len = n.length();
        result[0] = (int64_t)pow(10, len) + 1;
        result[1] = (int64_t)pow(10, len - 1) - 1;

        int64_t prefix = stol(n.substr(0, (len + 1) / 2));
        int j = 2;
        for (int i : {prefix, prefix - 1, prefix + 1})
        {
            string prefix = to_string(i);
            string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
            result[j++] = stol(candidate);
        }

        return result;
    }

    string pickCandidate(const std::array<int64_t, 5> &candidates, const string &self)
    {
        int64_t closest = -1;
        int64_t s = stol(self);
        for (int64_t c : candidates)
        {
            if (c == s)
            {
                continue;
            }
            if (closest == -1 ||
                abs(c - s) < abs(closest - s) ||
                (abs(c - s) == abs(closest - s) && c < closest))
            {
                closest = c;
            }
        }

        return to_string(closest);
    }
};

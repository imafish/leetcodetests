#include "afx.h"
using namespace std;

class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        auto changeX = [&](char x) -> int
        {
            int left = 0;
            int count = 0;
            int result = 0;
            int current = 0;
            for (int right = 0; right < answerKey.size(); right++)
            {
                current++;
                char &c = answerKey[right];
                if (c != x)
                {
                    count++;
                    if (count > k)
                    {
                        while (answerKey[left++] == x)
                        {
                        }
                        current = right - left + 1;
                        count = k;
                    }
                }
                if (current > result)
                {
                    result = current;
                }
            }
            return result;
        };

        return max(changeX('T'), changeX('F'));
    }
};

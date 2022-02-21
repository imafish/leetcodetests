#include "afx.h"
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> result;
        int sz = words.size();
        int strLen = s.length();
        int wordLen = words[0].length();

        unordered_map<string, int> wordMap;
        for (const auto &w : words)
        {
            wordMap[w]++;
        }

        unordered_map<string, int> wordLog;
        for (int i = 0; i < wordLen; i++)
        {
            int start = i;
            int end = i;
            int matched = 0;
            wordLog.clear();
            for (;;)
            {
                if (end + wordLen > strLen)
                {
                    break;
                }
                string word = string(&s[end], wordLen);
                auto iter = wordMap.find(word);
                if (iter == wordMap.end())
                {
                    // not found
                    wordLog.clear();
                    matched = 0;
                    start = end + wordLen;
                    end = start;
                }
                else
                {
                    // found.
                    int &cnt = wordLog[word];
                    if (cnt < iter->second)
                    {
                        ++cnt;
                        ++matched;
                        if (matched == sz)
                        {
                            result.push_back(start);
                            string toRemove(&s[start], wordLen);
                            wordLog[toRemove]--;
                            matched--;
                            start += wordLen;
                        }
                    }
                    else
                    {
                        // move forward until we reach another instance of word
                        // pop that from log
                        for (string wordToRemove; (wordToRemove = string(&s[start], wordLen)) != word; start += wordLen)
                        {
                            --wordLog[wordToRemove];
                            --matched;
                        }
                        start += wordLen;
                    }
                    end += wordLen;
                }
            }
        }

        return result;
    }
};

int main()
{
    string str = "wordgoodgoodgoodbestword";
    vector<string> words{"word", "good", "best", "good"};

    Solution s;
    s.findSubstring(str, words);
}

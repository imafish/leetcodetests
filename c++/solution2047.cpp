#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution2047
{
public:
    int countValidWords(string sentence)
    {
        int len = sentence.length();
        int cntValidWords = 0;
        int i = 0;
        int going = true;

        bool alreadyHasHyphen = false;
        bool validWord = false;
        bool inWord = false;
        char c = sentence[i];
        CharType ct = GetCharType(c);
        while (going)
        {
            if (ct == CharType_TERMINATOR)
            {
                going = false;
                if (validWord)
                {
                    cntValidWords++;
                }
                break;
            }

            CharType ct2 = GetCharType(sentence[++i]);

            if (!inWord)
            {
                if (ct != CharType_SPACE)
                {
                    inWord = true;
                    validWord = true;
                }
            }

            if (inWord)
            {
                if (ct == CharType_SPACE)
                {
                    if (validWord)
                    {
                        cntValidWords++;
                    }
                    inWord = false;
                    validWord = false;
                    alreadyHasHyphen = false;
                }
                else if (ct == CharType_NUMBER)
                {
                    validWord = false;
                }
                else if (ct == CharType_HYPHEN)
                {
                    if (alreadyHasHyphen)
                    {
                        validWord = false;
                    }
                    else if (ct2 != CharType_CHAR)
                    {
                        validWord = false;
                    }
                    else
                    {
                        // not very good here, refactor later.
                        // previous character must be letter.
                        int j = i - 2;
                        if (j < 0 || sentence[j] < 'a' || sentence[j] > 'z')
                        {
                            validWord = false;
                        }
                    }

                    alreadyHasHyphen = true;
                }
                else if (ct == CharType_PUNCTURE)
                {
                    if (ct2 != CharType_SPACE && ct2 != CharType_TERMINATOR)
                    {
                        validWord = false;
                    }
                }
            }

            ct = ct2;
        }

        return cntValidWords;
    }

private:
    enum CharType
    {
        CharType_CHAR,
        CharType_NUMBER,
        CharType_HYPHEN,
        CharType_PUNCTURE,
        CharType_SPACE,
        CharType_TERMINATOR,
        CharType_INVALID,
    };

    inline CharType GetCharType(char c)
    {
        if (c >= 'a' && c <= 'z')
        {
            return CharType_CHAR;
        }
        else if (c >= '0' && c <= '9')
        {
            return CharType_NUMBER;
        }
        else if (c == '-')
        {
            return CharType_HYPHEN;
        }
        else if (c == '.' || c == ',' || c == '!')
        {
            return CharType_PUNCTURE;
        }
        else if (c == ' ')
        {
            return CharType_SPACE;
        }
        else if (c == '\0')
        {
            return CharType_TERMINATOR;
        }
        else
        {
            return CharType_INVALID;
        }
    }
};

int main()
{
    std::vector<std::pair<const char *, int>> testcases{
        {"", 0},       // empty string
        {" ", 0},      // only one space
        {"      ", 0}, // many spaces
        {"1-", 0},
        {"-a", 0},
        {"!16-", 0},
        {"abc,,", 0},
        {"23", 0},
        {"1", 0},
        {"83ooj", 0},
        {"n!88qyfjly", 0},
        {"cat and   dog", 3},
        {"!this  1-s b8d!", 0},
        {"alice and  bob are playing stone-game10", 5},
        {"he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.", 6},
        {"qte1i   1-,, yv03a  r12r2stw 4 d,tnirlsj pb !16- 9 b  dnlgrig 8   n!88qyfjly   0g f5hgfg0u9lux7 - 6ega 0p36 pnw  ae  0m  -v  q3zdw09b9qju q0! s-  jk 04 e1ik  2 3  k a1qe.ac,-w j,keef76xz8  -!zhc s b u -z. ,,b -rei 83ooj 899 af w1irv u o3jk21 71i60pq3,.rzbhc.-  t9 xlk5g  ovn 8f9  ztw 7siy p-yl856r, ma39xtl!t-o c 2x 2 drj!ms0w ysy  u0tcw8u.im c 0ke.5sk  dn8.mh qi   8xmt -bxmr  z 1r 5 umyk 8rbe!dif kmes n rp icnb s 0yc1e 8  e1 !f  .u lh  n a -iinnm!a08dfgq ,lux,j 8fyqt hcbajnb4swuxtqm4j1  ic04 o,i4lka id 0srlb  y 2k  1g  3m nptj   53rh, zim7mkd2hqf64 chotiijcemj!m dif7iiq m2e ve!9!r1 jw okyahf! r6kskaodd h eug.yc,3j ilkd 9vlpipfc  g5y   7u 5pt531!4s 4  si !lg x50-   kc51ca34s pl 9w,mgj3  5fy,.3d shi ct a k2nx8l xum9sgyp6r   rj! 8  m!1k gm  typy . oee08!!j0,2iwq  9 ywd w rhpoc s6118y c5.qw4d  tlrjs.!9 mpioexe. xmicv  ,z g2 p6 bhtm!  ,w 7", 50},
    };

    Solution2047 s;
    int total = testcases.size();
    int passed = 0;
    for (auto &tc : testcases)
    {
        int actual = s.countValidWords(tc.first);
        if (actual == tc.second)
        {
            passed++;
        }
        std::cout << (actual == tc.second ? "SUCCESS: " : "FAIL   : ")
                  << "`" << tc.first
                  << "`, expected: " << tc.second
                  << ", actual: " << actual << std::endl;
    }

    std::cout << std::endl;
    std::cout << "TOTAL  : " << total
              << ", passed: " << passed
              << std::endl;
}

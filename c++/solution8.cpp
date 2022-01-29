#include "afx.h"

using namespace std;

class Solution8
{
public:
    int myAtoi(std::string s)
    {
        InternalState state{true, 0};

        string::iterator begin = s.begin();
        string::iterator end = s.end();
        RemoveLeadingCharacters(begin, end, state);
        GetSymbol(begin, end, state);
        GetNumbers(begin, end, state);
        ProcessNumbers(begin, end, state);

        return state.currentValue;
    }

private:
    struct InternalState
    {
        bool isPositive;
        int currentValue;
    };

    void RemoveLeadingCharacters(std::string::iterator &begin, std::string::iterator &end, InternalState &state)
    {
        while (begin != end && *begin == ' ')
        {
            begin++;
        }
    }

    void GetSymbol(std::string::iterator &begin, std::string::iterator &end, InternalState &state)
    {
        if (begin != end)
        {
            if (*begin == '+')
            {
                state.isPositive = true;
                begin++;
            }
            else if (*begin == '-')
            {
                state.isPositive = false;
                begin++;
            }
        }
    }

    void GetNumbers(std::string::iterator &begin, std::string::iterator &end, InternalState &state)
    {
        auto b = begin;

        while (begin != end && *begin >= '0' && *begin <= '9')
        {
            begin++;
        }

        end = begin;
        begin = b;
    }

    void ProcessNumbers(std::string::iterator &begin, std::string::iterator &end, InternalState &state)
    {
        int value = 0;

        const int threshold = 0x7fffffff / 10;
        int remainder = 0x7fffffff % 10;
        if (!state.isPositive)
        {
            remainder = remainder + 1;
        }

        while (begin != end)
        {
            int newValue = *begin - 48;

            // TODO move to separate function.
            if (value > threshold || (value == threshold && newValue > remainder))
            {
                state.currentValue = state.isPositive ? 0x7fffffff : (int32_t)0x80000000;
                return;
            }

            value = value * 10 + (*begin - 48);
            begin++;
        }

        if (!state.isPositive)
        {
            value = -value;
        }

        state.currentValue = value;
    }
};

int main()
{
    Solution8 s;
    std::string str = "42";
    int expected = 42;
    int actual = s.myAtoi(str);

    if (actual == expected)
    {
        std::cout << "SUCCESS";
    }
    else
    {
        std::cout << "FAIL: expected : " << expected
                  << ", actual: " << actual;
    }
    std::cout << std::endl;
}

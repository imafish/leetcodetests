#include "afx.h"

using namespace std;

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        _in.push(value);
    }

    int deleteHead()
    {
        if (_out.empty())
        {
            while (!_in.empty())
            {
                _out.push(_in.top());
                _in.pop();
            }
        }

        if (_out.empty())
        {
            return -1;
        }

        int result = _out.top();
        _out.pop();
        return result;
    }

private:
    stack<int> _in;
    stack<int> _out;
};

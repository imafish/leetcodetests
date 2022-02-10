#include "afx.h"

using namespace std;

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        _data.push(x);
        if (_minStack.empty() || x <= _minStack.top())
        {
            _minStack.push(x);
        }
    }

    void pop()
    {
        int v = _data.top();
        _data.pop();
        if (v == _minStack.top())
        {
            _minStack.pop();
        }
    }

    int top()
    {
        return _data.top();
    }

    int min()
    {
        return _minStack.top();
    }

private:
    stack<int> _data;
    stack<int> _minStack;
};

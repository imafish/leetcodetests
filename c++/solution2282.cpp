#include "afx.h"
using namespace std;

class MaxQueue
{
public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (_maxQueue.empty())
        {
            return -1;
        }
        return _maxQueue.front();
    }

    void push_back(int value)
    {
        _data.push(value);

        while (!_maxQueue.empty() && value > _maxQueue.back())
        {
            _maxQueue.pop_back();
        }
        _maxQueue.push_back(value);
    }

    int pop_front()
    {
        if (_data.empty())
        {
            return -1;
        }

        int value = _data.front();
        _data.pop();

        if (value == _maxQueue.front())
        {
            _maxQueue.pop_front();
        }
        return value;
    }

private:
    queue<int> _data;
    deque<int> _maxQueue;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

#include "afx.h"

using namespace std;

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (_smaller.size() < _larger.size())
        {
            _larger.push(num);
            _smaller.push(_larger.top());
            _larger.pop();
        }
        else
        {
            _smaller.push(num);
            _larger.push(_smaller.top());
            _smaller.pop();
        }
    }

    double findMedian()
    {
        if (_smaller.size() < _larger.size())
        {
            return double(_larger.top());
        }
        else
        {
            return (double(_smaller.top()) + _larger.top()) / 2;
        }
    }

private:
    std::priority_queue<int> _smaller;
    std::priority_queue<int, vector<int>, greater<int>> _larger;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl;
    mf.addNum(3);
    cout << mf.findMedian() << endl;
}

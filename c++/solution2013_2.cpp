#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <iostream>
#include <array>

using namespace std;

class DetectSquares
{
public:
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        std::array<int, 2> p{x, y};

        auto i = _data.find(p);
        bool hasRecord = false;
        if (i != _data.end())
        {
            hasRecord = true;
            i->second = i->second + 1;
        }
        else
        {
            _data[p] = 1;
        }

        auto j = _mapWithY.find(y);
        if (j != _mapWithY.end())
        {
            _mapWithY[y].insert(x);
        }
        else
        {
            std::unordered_set<int> s{x};
            _mapWithY.insert(std::pair<int, std::unordered_set<int>>(y, std::move(s)));
        }
    }

    int count(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        int p[2]{x, y};

        int total = 0;

        // iterate through points with same 'Y'
        auto i = _mapWithY.find(y);
        if (i == _mapWithY.end())
        {
            return 0;
        }
        else
        {
            for (auto xi : i->second)
            {
                if (xi == x)
                {
                    continue;
                }

                // p1: (xi, y)
                std::array<int, 2> p1{xi, y};

                int width = x - xi;
                int y1 = y + width;
                int y2 = y - width;

                // p2-1: (xi, y1)
                // p3-1: (x, y1)
                std::array<int, 2> p21{xi, y1};
                std::array<int, 2> p31{x, y1};
                total += _data[p1] * _data[p21] * _data[p31];

                // p2-2: (xi, y2)
                // p3-2: (x, y2)
                std::array<int, 2> p22{xi, y2};
                std::array<int, 2> p32{x, y2};
                total += _data[p1] * _data[p22] * _data[p32];
            }
        }

        return total;
    }

    class Hasher
    {
    public:
        std::size_t operator()(const std::array<int, 2> &v) const
        {
            return v[0] * v[1];
        }
    };

    class Equaler
    {
    public:
        bool operator()(const std::array<int, 2> &l, const std::array<int, 2> &r) const
        {
            return l[0] == r[0] && l[1] == r[1];
        }
    };

private:
    static std::function<std::size_t(const vector<int> &)> _hashFunc;
    static std::function<bool(const vector<int> &, const vector<int> &)> _equalFunc;

private:
    std::unordered_map<std::array<int, 2>, int, Hasher, Equaler> _data;
    std::unordered_map<int, std::unordered_set<int>> _mapWithY;
};

// TODO: research how to user function<> as hasher and equaler for unordered_map
std::function<std::size_t(const vector<int> &)> DetectSquares::_hashFunc = [](const vector<int> &v) -> std::size_t
{
    return v[0] * v[1];
};

std::function<bool(const vector<int> &, const vector<int> &)>
    DetectSquares::_equalFunc = [](const vector<int> &l, const vector<int> &r) -> bool
{
    return l[0] == r[0] && l[1] == r[1];
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

void Add(DetectSquares *obj, int x, int y)
{
    std::vector<int> p{x, y};
    obj->add(p);
}

void Count(DetectSquares *obj, int x, int y, int expected)
{
    std::vector<int> p{x, y};
    int actual = obj->count(p);

    std::cout << (actual == expected ? "SUCCESS: " : "FAIL   : ")
              << "expected: " << expected << ", actual: " << actual << std::endl;
}

int main()
{
    DetectSquares *obj = new DetectSquares();
    Add(obj, 3, 10);
    Add(obj, 11, 2);
    Add(obj, 3, 2);
    Count(obj, 11, 10, 1);
    Count(obj, 14, 8, 0);
    Add(obj, 11, 2);
    Count(obj, 11, 10, 2);

    return 0;
}

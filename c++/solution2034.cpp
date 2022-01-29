#include <unordered_map>
#include <map>
#include <iostream>

class StockPrice
{
public:
    StockPrice()
        : current_timestamp(0),
          current_price(0),
          min(0),
          max(0),
          min_valid(false),
          max_valid(false)
    {
    }

    void update(int timestamp, int price)
    {
        update_current(timestamp, price);
        update_history(timestamp, price);
    }

    int current()
    {
        return current_price;
    }

    int maximum()
    {
        if (!max_valid)
        {
            find_max();
            max_valid = true;
        }
        return max;
    }

    int minimum()
    {
        if (!min_valid)
        {
            find_min();
            min_valid = true;
        }
        return min;
    }

private:
    void update_current(int timestamp, int price)
    {
        if (timestamp >= current_timestamp)
        {
            current_timestamp = timestamp;
            current_price = price;
        }
    }
    void update_history(int timestamp, int price)
    {
        if (history.find(timestamp) != history.end())
        {
            // remove old value from cache
            int old_price = history[timestamp];
            int old_count = reverse_history[old_price];
            if (old_count == 1)
            {
                reverse_history.erase(old_price);
            }
            else
            {
                reverse_history[old_price] = old_count - 1;
            }

            if (old_price == min)
            {
                min_valid = false;
            }
            if (old_price == max)
            {
                max_valid = false;
            }
        }

        history[timestamp] = price;
        reverse_history[price]++;
        if (price < min)
        {
            min = price;
            min_valid = true;
        }
        if (price > max)
        {
            max = price;
            max_valid = true;
        }
    }

    void find_min()
    {
        min = reverse_history.begin()->first;
    }

    void find_max()
    {
        max = reverse_history.rbegin()->first;
    }

    int current_timestamp;
    int current_price;
    bool min_valid;
    bool max_valid;
    int max;
    int min;
    std::unordered_map<int, int> history;
    std::map<int, int> reverse_history;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
void print(StockPrice *p)
{
    int param_2 = p->current();
    int param_3 = p->maximum();
    int param_4 = p->minimum();

    std::cout << param_2 << " "
              << param_3 << " "
              << param_4 << std::endl;
}

int main()
{
    StockPrice *obj = new StockPrice();
    obj->update(2, 3);
    print(obj);

    obj->update(3, 4);
    print(obj);

    obj->update(2, 5);
    print(obj);

    return 0;
}

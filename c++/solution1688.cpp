class Solution
{
public:
    int numberOfMatches(int n)
    {
        int total = 0;
        while (n > 1)
        {
            total += n / 2;
            if (n % 2 == 1)
            {
                n = n / 2 + 1;
            }
            else
            {
                n = n / 2;
            }
        }

        return total;
    }
};

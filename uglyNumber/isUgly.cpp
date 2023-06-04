#include <vector>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    bool isUgly(int n)
    {
        if (n <= 0) return false;

        std::vector<int> factors = {2, 3, 5};
        for (int factor : factors)
        {
            while (n % factor == 0)
            {
                n /= factor;
            }
        }

        return n == 1;
    }
#endif

#if method2
    bool isUgly(int n)
    {
        if (n <= 0) return false;

        while (n % 2 == 0)
        {
            n /= 2;
        }

        while (n % 3 == 0)
        {
            n /= 3;
        }

        while (n % 5 == 0)
        {
            n /= 5;
        }

        return n == 1;
    }
#endif
};

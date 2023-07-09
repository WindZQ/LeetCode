#include <vector>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class Solution
{
public:
#if method1
    std::vector<int> countBits(int n)
    {
        std::vector<int> res(n + 1);

        for (int i = 0; i <= n; ++i)
        {
            res[i] = count_ones(i);
        }

        return res;
    }

    int count_ones(int x)
    {
        int ones = 0;

        while (x > 0)
        {
            x &= (x - 1);
            ones++;
        }

        return ones;
    }
#endif

#if method2
    std::vector<int> countBits(int n)
    {
        std::vector<int> res(n + 1);
        int high = 0;

        for (int i = 1; i <=n; ++i)
        {
            if ((i &(i - 1)) == 0)
            {
                high = i;
            }

            res[i] = res[i - high] + 1;
        }

        return res;
    }
#endif

#if method3
    std::vector<int> countBits(int n)
    {
        std::vector<int> res(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }
#endif

#if method4
    std::vector<int> countBits(int n)
    {
        std::vector<int> res(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            res[i] = res[i & (i - 1)] + 1;
        }

        return res;
    }
#endif
};

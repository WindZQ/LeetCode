#include <math>
#include <vector>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int climbStairs(int n)
    {
        int p = 0, q = 0, r = 1;

        for (int i = 1; i <= n; ++i)
        {
            p = q;
            q = r;
            r = p + q;
        }

        return r;
    }
#endif

#if method2
    std::vector<std::vector<long long>> multiply(std::vector<std::vector<long long>> &a, std::vector<std::vector<long long>> &b)
    {
        std::vector<std::vector<long long>> c(2, std::vector<long long>(2));

        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }

        return c;
    }

    std::vector<std::vector<long long>> matrix_pow(std::vector<std::vector<long long>> a, int n)
    {
        std::vector<std::vector<long long>> res = {{1, 0}, {0, 1}};

        while (n > 0)
        {
            if ((n & 1) == 1) res = multiply(res, a);

            n >>= 1;
            a = multiply(a, a);
        }

        return res;
    }

    int climbStairs(int n)
    {
        std::vector<std::vector<long long>> ret = {{1, 1}, {1, 0}};
        std::vector<std::vector<long long>> res = matrix_pow(ret, n);

        return res[0][0];
    }
#endif

#if method3
    int climbStairs(int n)
    {
        double sqrt5 = std::sqrt(5);
        double f = std::pow((1 + sqrt5) / 2, n + 1) - std::pow((1 - sqrt5) / 2, n + 1);

        return (int)round(f / sqrt5);
    }
#endif
};

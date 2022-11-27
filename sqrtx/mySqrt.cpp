#include <math>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int mySqrt(int x)
    {
        if (x == 0) return 0;

        int res = exp(0.5 * log(x));
        return ((long long)(res + 1) * (res + 1) <= x ? res + 1 : res);
    }
#endif

#if method2
    int mySqrt(int x)
    {
        int l = 0, r = x, res = -1;

        while (l <= r)
        {
            int mid = l + (r - l ) / 2;
            if ((long long)mid * mid <= x)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return res;
    }
#endif

#if method3
    int mySqrt(int x)
    {
        if (x == 0) return 0;

        double c = x, x0 = x;
        while (1)
        {
            double xi = 0.5 * (x0 + c / x0);

            if (fabs(x0 - xi) < 1e-7)
            {
                break;
            }

            x0 = xi;
        }

        return int(x0);
    }
#endif
};

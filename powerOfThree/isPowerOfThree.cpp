#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isPowerOfThree(int n)
    {
        while (n && n % 3 == 0)
        {
            n /= 3;
        }

        return n == 1;
    }
#endif

#if method2
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
#endif
};

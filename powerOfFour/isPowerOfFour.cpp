#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n &(n - 1)) == 0 && n % 3 == 1;
    }
#endif

#if method2
    bool isPowerOfFour(int n)
    {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
#endif
};

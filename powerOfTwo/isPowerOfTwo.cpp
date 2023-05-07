#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
#endif

#if method2
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (1 << 30) % n == 0;
    }
#endif
};

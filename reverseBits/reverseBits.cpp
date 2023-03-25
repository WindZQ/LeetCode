
#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;

        for (int i = 0; i < 32 && n > 0; ++i)
        {
            res |= (n & 1) << (31 - i);
            n >>= 1;
        }

        return res;
    }
#endif

#if method2
    uint32_t reverseBits(uint32_t n)
    {
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
private:
    const uint32_t M1 = 0x55555555;
    const uint32_t M2 = 0x33333333;
    const uint32_t M4 = 0x0f0f0f0f;
    const uint32_t M8 = 0x00ff00ff;
#endif
};

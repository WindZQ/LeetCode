#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i] += 1;

                return digits;
            }
        }

        std::vector<int> res(n + 1);
        res[0] = 1;

        return res;
    }
#endif

#if method2
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        int n = digits.size();
        while (n && ++digits[--n] == 10) digits[n] = 0;
        if (digits[0] == 0) digits.insert(begin(digits), 1);

        return digits;
    }
#endif
};

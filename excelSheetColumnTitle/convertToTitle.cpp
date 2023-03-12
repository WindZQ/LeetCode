#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string convertToTitle(int columnNumber)
    {
        std::string res;

        while (columnNumber > 0)
        {
            --columnNumber;
            res += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
#endif

#if method2
    std::string convertToTitle(int columnNumber)
    {
        std::string res;

        while (columnNumber > 0)
        {
            int a = (columnNumber - 1) % 26 + 1;
            res += a - 1 + 'A';
            columnNumber = (columnNumber - a) / 26;
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
#endif
};

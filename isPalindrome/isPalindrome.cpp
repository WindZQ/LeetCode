#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isPalindrome(int x)
    {
        std::string str = to_string(x);
        std::string rstr = std::string(str.rbegin(), str.rend());

        return str == rstr;
    }
#endif

#if method2
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int number = 0;
        while (x > number)
        {
            number = number * 10 + x % 10;
            x /= 10;
        }

        return x == number || x == number / 10;
    }
#endif
}

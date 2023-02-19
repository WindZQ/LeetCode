#include <string>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    bool isPalindrome(std::string s)
    {
        std::string res;
        for (char ch : s)
        {
            if (isalnum(ch))
            {
                res += tolower(ch);
            }
        }

        std::string res_rev(res.rbegin(), res.rend());

        return res == res_rev;
    }
#endif

#if method2
    bool isPalindrome(std::string s)
    {
        std::string res;

        for (char ch : s)
        {
            if (isalnum(ch))
            {
                res += tolower(ch);
            }
        }

        int n = res.size();
        int left = 0, right = n - 1;

        while (left < right)
        {
            if (res[left] != res[right])
            {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
#endif

#if method3
    bool isPalindrome(std::string s)
    {
        int n = s.size();
        int left = 0, right = n - 1;

        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
            {
                ++left;
            }

            while (left < right && !isalnum(s[right]))
            {
                --right;
            }

            if (left < right)
            {
                if (tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }
                ++left;
                --right;
            }
        }

        return true;
    }
#endif
};

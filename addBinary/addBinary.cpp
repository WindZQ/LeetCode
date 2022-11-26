#include <string>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::string addBinary(std::string a, std::string b)
    {
        std::string res;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        int n = std::max(a.size(), b.size()), carry = 0;

        for (int i = 0; i < n; ++i)
        {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            res.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) res.push_back('1');

        std::reverse(res.begin(), res.end());

        return res;
    }
#endif

#if method2
    std::string addBinary(std::string a, std::string b)
    {
        int a_size = a.size(), b_size = b.size();
        while (a_size > b_size)
        {
            b = '0' + b;
            b_size++;
        }

        while (a_size < b_size)
        {
            a = '0' + a;
            a_size++;
        }

        int carry = 0;
        for (int i = a_size - 1; i >= 0; --i)
        {
            int sum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = sum % 2 + '0';
            carry = sum / 2;
        }

        if (carry > 0) a = '1' + a;

        return a;
    }
#endif
};

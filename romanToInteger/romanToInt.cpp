#include <string>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int romanToInt(std::string s)
    {
        std::unordered_map<char, int> values =
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int res = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i)
        {
            int value = values[s[i]];
            if (i < n - 1 && value < values[s[i + 1]])
            {
                res -= value;
            }
            else
            {
                res += value;
            }
        }

        return res;
    }
#endif

#if method2
    int romanToInt(std::string s)
    {
        std::unordered_map<std::string, int> m =
        {
            {"I", 1},
            {"IV", 3},
            {"IX", 8},
            {"V", 5},
            {"X", 10},
            {"XL", 30},
            {"XC", 80},
            {"L", 50},
            {"C", 100},
            {"CD", 300},
            {"CM", 800},
            {"D", 500},
            {"M", 1000}
        };

        int res = m[s.substr(0, 1)];

        for(int i = 1; i < s.length(); ++i)
        {
            std::string two = s.substr(i - 1, 2);
            std::string one = s.substr(i, 1);

            res += m[two] ? m[two] : m[one];
        }

        return res;
    }
#endif
};

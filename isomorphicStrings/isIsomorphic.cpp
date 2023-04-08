#include <string>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isIsomorphic(std::string s, std::string t)
    {
        std::unordered_map<char, char> s1, s2;
        int len = s.length();

        for (int i = 0; i < len; ++i)
        {
            char x = s[i], y = t[i];
            if ((s1.count(x) && s1[x] != y) || (s2.count(y) && s2[y] != x))
            {
                return false;
            }

            s1[x] = y;
            s2[y] = x;
        }

        return true;
    }
#endif

#if method2
    bool isIsomorphic(std::string s, std::string t)
    {
        if (s.size() != t.size()) return false;

        std::vector<int> v1(128, -1);
        std::vector<int> v2(128, -1);

        for (int i = 0; i < s.size(); ++i)
        {
            if (v1[s[i]] != -1 && v1[s[i]] != t[i])
            {
                return false;
            }
            else if (v1[s[i]] == -1)
            {
                v1[s[i]] = t[i];
            }

            if (v2[t[i]] != -1 && v2[t[i]] != s[i])
            {
                return false;
            }
            else if (v2[t[i]] == -1)
            {
                v2[t[i]] = s[i];
            }
         }

        return true;
    }
#endif
};

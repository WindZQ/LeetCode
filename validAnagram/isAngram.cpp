#include <string>
#include <algorithm>
#include <vector>


#define method1 1
#define method2 0

class Solution
{
#if method1
    bool isAnagram(std::string s, std::string t)
    {
        if (s.length() != t.length()) return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }
#endif

#if method2
    bool isAnagram(std::string s, std::string t)
    {
        if (s.length() != t.length()) return false;

        std::vector<int> table(26, 0);
        for (auto &ch : s)
        {
            table[ch - 'a']++;
        }

        for (auto &ch : t)
        {
            table[ch - 'a']--;

            if (table[ch - 'a'] < 0) return false;
        }

        return true;
    }
#endif
};

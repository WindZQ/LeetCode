#include <string>

class Solution
{
public:
    std::string reverseVowels(std::string s)
    {
        auto is_vowel = [vowels = "aeiouAEIOU"s](char ch)
        {
            return vowels.find(ch) != std::string::npos;
        };

        int n = s.size(), i = 0, j = n - 1;
        while (i < j)
        {
            while (i < n && !is_vowel(s[i]))
            {
                ++i;
            }

            while (j > 0 && !is_vowel(s[j]))
            {
                --j;
            }

            if (i < j)
            {
                std::swap(s[i], s[j]);
                ++i;
                --j;
            }
        }

        return s;
    }
};

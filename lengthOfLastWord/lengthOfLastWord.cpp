#include <string>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int lengthOfLastWord(std::string s)
    {
        int pos = s.rfind(" ");
        while (s.rfind(" ") == s.size() - 1)
        {
            s.erase(s.rfind(" "), 1);
        }

        return s.size() - (s.rfind(" ") + 1);
    }
#endif

#if method2
    int lengthOfLastWord(std::string s)
    {
        int last = s.size() - 1;
        while (s.at(last) == ' ') --last;
        int first = last;
        while ( first > -1 && s.at(first) != ' ') --first;

        return last - first;
    }
#endif
};

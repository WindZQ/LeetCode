#include <string>

class Solution
{
public:
    int titleToNumber(std::string columnTitle)
    {
        int res = 0;
        long multiple = 1;

        for (int i = columnTitle.size() - 1; i >= 0; --i)
        {
            int k = columnTitle[i] - 'A' + 1;
            res += k * multiple;
            multiple *= 26;
        }

        return res;
    }
};

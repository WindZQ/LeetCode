#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int singleNumber(std::vector<int>& nums)
    {
        int res = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            res ^= nums[i];
        }

        return res;
    }
#endif

#if method2
    int singleNumber(std::vector<int>& nums)
    {
        std::unordered_map<int, int> m;
        for (auto num : nums)
        {
            ++m[num];
        }

        for (auto [mp, res] : m)
        {
            if (res == 1) return mp;
        }

        return 0;
    }
#endif
};

#include <vector>
#include <algorithm>
#include <unordered_set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }

        return false;
    }
#endif

#if method2
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_set<int> s;

        for (int x : nums)
        {
            if (s.find(x) != s.end())
            {
                return true;
            }

            s.insert(x);
        }

        return false;
    }
#endif
};

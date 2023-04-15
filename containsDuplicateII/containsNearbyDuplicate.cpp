#include <vector>
#include <unordered_map>
#include <unordered_set>


#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> m;
        int len = nums.size();

        for (int i = 0; i < len; ++i)
        {
            int num = nums[i];

            if (m.count(num) & i - m[num] <= k)
            {
                return true;
            }

            m[num] = i;
        }

        return false;
    }
#endif

#if method2
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        std::unordered_set<int> s;
        int len = nums.size();

        for (int i = 0; i < len; ++i)
        {
            if (i > k)
            {
                s.erase(nums[i - k - 1]);
            }

            if (s.count(nums[i]))
            {
                return true;
            }

            s.emplace(nums[i]);
        }

        return false;
    }
#endif
};

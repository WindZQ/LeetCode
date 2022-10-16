#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
#endif

#if method2
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hash.find(target - nums[i]);

            if (it != hash.end())
            {
                return {it->second, i};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
#endif
};

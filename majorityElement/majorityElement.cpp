#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0
#define method3 0
#define method4 0


class Solution
{
public:
#if method1
    int majorityElement(std::vector<int>& nums)
    {
        std::unordered_map<int, int> m;
        int res = 0, count = 0;

        for (int num : nums)
        {
            ++m[num];
            if (m[num] > count)
            {
                res = num;
                count = m[num];
            }
        }

        return res;
    }
#endif

#if method2
    int majorityElement(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
#endif

#if method3
    int majorityElement(std::vector<int>& nums)
    {
        while (1)
        {
            int candidate = nums[rand() % nums.size()];
            int count = 0;

            for (int num : nums)
            {
                if (num == candidate)
                {
                    ++count;
                }
            }

            if (count > nums.size() / 2)
            {
                return candidate;
            }
        }

        return -1;
    }
#endif

#if method4
    int majorityElement(std::vector<int>& nums)
    {
        int candidate = -1, count = 0;

        for (int num : nums)
        {
            if (num == candidate)
            {
                ++count;
            }
            else if (--count < 0)
            {
                candidate = num;
                count = 1;
            }
        }

        return candidate;
    }
#endif
};

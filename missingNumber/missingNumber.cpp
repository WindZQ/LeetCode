#include <unordered_set>
#include <alogrithm>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class Solution
{
public:
#if method1
    int missingNumber(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i) return i;
        }

        return n;
    }
#endif

#if method1
    int missingNumber(std::vector<int>& nums)
    {
        std::unordered_set<int> s;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            s.insert(nums[i]);
        }

        int res = -1;
        for (int i = 0; i <= n; ++i)
        {
            if (!s.count(i))
            {
                res = i;
                break;
            }
        }

        return res;
    }
#endif

#if method3
    int missingNumber(std::vector<int>& nums)
    {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            res ^= nums[i];
        }

        for (int i = 0; i <= n; ++i)
        {
            res ^= i;
        }

        return res;
    }
#endif

#if method4
    int missingNumber(std::vector<int>& nums)
    {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int arr_sum = 0;

        for (int i = 0; i < n; ++i)
        {
            arr_sum += nums[i];
        }

        return total - arr_sum;
    }
#endif
};

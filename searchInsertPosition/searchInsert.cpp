#include <vector>

#define method1 1
#define method2 0


class Solution
{
public:
#if method1
    int searchInsert(std::vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = ((right - left) >> 1) + left;

            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
#endif

#if method2
    int searchInsert(std::vector<int>& nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
#endif
};

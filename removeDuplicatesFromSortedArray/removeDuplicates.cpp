#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        int fast = 1, slow = 1;

        while (fast < n)
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }

        return slow;
    }
};

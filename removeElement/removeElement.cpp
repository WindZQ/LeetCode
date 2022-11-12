#include <vector>

#define method1 1
#define method2 0
#define method3 0

class Solution
{
public:
#if method1
    int removeElement(std::vector<int>& nums, int val)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    nums[j - 1] = nums[j];
                }

                i--;
                n--;
            }
        }

        return n;
    }
#endif

#if method2
    int removeElement(std::vector<int>& nums, int val)
    {
        int n = nums.size(), slow = 0;

        for (int fast = 0; fast < n; ++fast)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                ++slow;
            }
        }

        return slow;
    }
#endif

#if method3
    int removeElement(std::vector<int>& nums, int val)
    {
        int slow = 0, fast = nums.size();

        while (slow < fast)
        {
            if (nums[slow] == val)
            {
                nums[slow] = nums[fast - 1];
                fast--;
            }
            else
            {
                slow++;
            }
        }

        return slow;
    }
#endif
};

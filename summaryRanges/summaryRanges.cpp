#include <vector>
#include <string>

class Solution
{
public:
#if method1
    std::vector<std::string> summaryRanges(std::vector<int>& nums)
    {
        std::vector<std::string> res;
        int left = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i + 1 == nums.size() || nums[i] + 1 != nums[i + 1])
            {
                res.push_back(std::to_string(nums[left]) + (left == i ? "" : "->" + std::to_string(nums[i])));
                left = i + 1;
            }
        }

        return res;
    }
#endif

#if method2
    std::vector<std::string> summaryRanges(std::vector<int>& nums)
    {
        std::vector<std::string> res;
        int n = nums.size();

        if (n == 0) return res;

        int i = 0, j = 0;
        while (i < n)
        {
            while (j + 1 < n && nums[j + 1] == nums[j] + 1)
            {
                ++j;
            }

            if (i != j)
            {
                res.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[j]));
            }
            else
            {
                res.push_back(std::to_string(nums[i]));
            }

            i = j + 1;
            j = i;
        }

        return res;
    }
#endif
};

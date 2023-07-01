#include <vector>

#define method1 1
#define mehtod2 0

class Solution
{
public:
#if mehtod1
	void moveZeroes(std::vector<int>& nums)
	{
		int n = nums.size(), left = 0, right = 0;
		
		while (right < n)
		{
			if (nums[right])
			{
				std::swap(nums[left], nums[right]);
				left++;
			}
			
			right++;
		}
	}
#endif

#if mehtod2
	void moveZeroes(std::vector<int>& nums)
	{
		int i = 0;
		
		for (int j = 0; j < nums.size(); ++j)
		{
			if (nums[j])
			{
				nums[i++] = nums[j];
			}
		}
		
		for (; i < nums.size(); ++i)
		{
			nums[i] = 0;
		}	
	}
#endif
};

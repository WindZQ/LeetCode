#include <vector>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
    {
		if (nums1.size() > nums2.size()) 
		{
			return intersect(nums2, nums1);
		}
		
		std::unordered_map<int, int> m;
		for (int num : nums1)
		{
			++m[num];
		}
		
		std::vector<int> res;
		for (int num : nums2)
		{
			if (m.count(num))
			{
				res.push_back(num);
				--m[num];
				
				if (m[num] == 0)
				{
					m.erase(num);
				}
			}
		}
		
		return res;
    }
#endif

#if method2
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int len1 = nums1.size(), len2 = nums2.size();
        int index1 = 0, index2 = 0;
        std::vector<int> res;

        while (index1 < len1 && index2 < len2)
        {
			if (nums1[index1] < nums2[index2])
			{
				index1++;
			}
			else if (nums1[index1] > nums2[index2])
			{
				index2++;
			}
			else 
			{
				res.push_back(nums1[index1]);
				index1++;
				index2++;
			}
        }
		
        return res;
    }
#endif
};

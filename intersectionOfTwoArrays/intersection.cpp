#include <vector>
#include <unordered_set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_set<int> s1, s2;

        for (auto &num : nums1)
        {
            s1.insert(num);
        }

        for (auto &num : nums2)
        {
            s2.insert(num);
        }

        return get_intersection(s1, s2);
    }

    std::vector<int> get_intersection(std::unordered_set<int>& s1, std::unordered_set<int>& s2)
    {
        if (s1.size() > s2.size())
        {
            return get_intersection(s2, s1);
        }

        std::vector<int> res;
        for (auto& num : s1)
        {
            if (s2.count(num))
            {
                res.push_back(num);
            }
        }

        return res;
    }
#endif

#if method2
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int len1 = nums1.size(), len2 = nums2.size();
        int index1 = 0, index2 = 0;
        std::vector<int> res;

        while (index1 < len1 && index2 < len2)
        {
            int num1 = nums1[index1], num2 = nums2[index2];

            if (num1 == num2)
            {
                if (!res.size() || num1 != res.back())
                {
                    res.push_back(num1);
                }

                index1++;
                index2++;
            }
            else if (num1 < num2)
            {
                index1++;
            }
            else
            {
                index2++;
            }
        }

        return res;
    }
#endif
};

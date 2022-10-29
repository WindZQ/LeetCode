#include <string>
#include <vector>

#define method1 1
#define method2 0
#define method3 0
#define method4 0
#define method5 0


class Solution
{
public:
#if method1
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty()) return std::string();

        std::string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            prefix = help(prefix, strs[i]);

            if (prefix.empty()) break;
        }

        return prefix;
    }

    std::string help(std::string& str1, std::string& str2)
    {
        int length = std::min(str1.size(), str2.size());
        int i = 0;

        while (i < length && str1[i] == str2[i])
        {
            ++i;
        }

        return str1.substr(0, i);
    }
#endif

#if method2
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty()) return std::string();

        int length = strs[0].size();
        int count = strs.size();

        for (int i = 0; i < length; ++i)
        {
            char c = strs[0][i];

            for (int j = 1; j < count; ++j)
            {
                if (i == strs[j].size() || strs[j][i] != c)
                {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
#endif

#if method3
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (strs.empty())
        {
            return std::string();
        }
        else
        {
            return help(strs, 0, strs.size() - 1);
        }
    }

    std::string help(const std::vector<std::string>& strs, int start, int end)
    {
        if (start == end)
        {
            return strs[start];
        }
        else
        {
            int mid = (start + end) / 2;
            std::string left = help(strs, start, mid);
            std::string right = help(strs, mid + 1, end);
            return common_prexif(left, right);
        }
    }

    std::string common_prexif(const std::string& left, const std::string& right)
    {
        int length = std::min(left.size(), right.size());

        for (int i = 0; i < length; ++i)
        {
            if (left[i] != right[i])
            {
                return left.substr(0, i);
            }
        }

        return left.substr(0, length);
    }
#endif

#if method4
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty()) return std::string();

        int length = min_element(strs.begin(), strs.end(), [](const std::string& s, const std::string &t) { return s.size() < t.size();})->size();
        int low = 0, high = length;

        while (low < high)
        {
            int mid = (high - low + 1) / 2 + low;

            if (is_common_prefix(strs, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        return strs[0].substr(0, low);
    }

    bool is_common_prefix(const std::vector<std::string>& strs, int length)
    {
        std::string temp_str = strs[0].substr(0, length);
        int count = strs.size();

        for (int i = 1; i < count; ++i)
        {
            std::string str = strs[i];

            for (int j = 0; j < length; ++j)
            {
                if (temp_str[j] != str[j])
                {
                    return false;
                }
            }
        }

        return true;
    }
#endif

#if method5
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty()) return std::string();

        std::sort(strs.begin(), strs.end());
        std::string st = strs.front(), en = strs.back();
        int i;
        int num = std::min(st.size(), en.size());

        for (i = 0; i < num && st[i] == en[i]; ++i);

        return std::string(st, 0, i);
    }
#endif
};

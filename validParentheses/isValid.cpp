#include <stack>
#include <string>
#include <unordered_map>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isValid(std::string s)
    {
        if (s.size() % 2 != 0) return false;
        std::stack<char> st;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(')');
            }
            else if (s[i] == '{')
            {
                st.push('}');
            }
            else if (s[i] == '[')
            {
                st.push(']');
            }
            else if (st.empty() || st.top() != s[i])
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }

        return st.empty();
    }
#endif

#if method2
    bool isValid(std::string s)
    {
        int n = s.size();
        if (n % 2 == 1) return false;

        std::unordered_map<char, char> pairs =
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        std::stack<char> st;

        for (char ch : s)
        {
            if (pairs.count(ch))
            {
                if (st.empty() || st.top() != pairs[ch])
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        return st.empty();
    }
#endif
};

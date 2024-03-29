#include <vector>

#define method1 1
#define method2 0
#define method3 0
#define method4 0

class Solution
{
public:
#if method1
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<std::vector<int>> res(rowIndex + 1);

        for (int i = 0; i <= rowIndex; ++i)
        {
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;

            for (int j = 1; j < i; ++j)
            {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }

        return res[rowIndex];
    }
#endif

#if method2
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> pre, cur;

        for (int i = 0; i <= rowIndex; ++i)
        {
            cur.resize(i + 1);
            cur[0] = cur[i] = 1;

            for (int j = 1; j < i; ++j)
            {
                cur[j] = pre[j - 1] + pre[j];
            }
            pre = cur;
        }

        return pre;
    }
#endif

#if method3
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> res(rowIndex + 1);
        res[0] = 1;

        for (int i = 1; i <= rowIndex; ++i)
        {
            for (int j = i; j > 0; --j)
            {
                res[j] += res[j - 1];
            }
        }

        return res;
    }
#endif

#if method4
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> res(rowIndex + 1);
        res[0] = 1;

        for (int i = 1; i <= rowIndex; ++i)
        {
            res[i] = 1LL * res[i - 1] * (rowIndex - i + 1) / i;
        }

        return res;
    }
#endif
};

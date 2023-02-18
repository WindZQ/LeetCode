#include <vector>
#include <algorithm>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    int maxProfit(std::vector<int>& prices)
    {
        if (prices.size() <= 1) return 0;

        int smallest = prices[0];
        int res = INT_MIN;

        for (int i = 1; i < prices.size(); ++i)
        {
            res = std::max(res, prices[i] - smallest);
            smallest = std::min(smallest, prices[i]);
        }

        return std::max(0, res);
    }
#endif

#if method2
    int maxProfit(std::vector<int>& prices)
    {
        int inf = 1e9;
        int min_price = inf, res = 0;

        for (int price : prices)
        {
            res = std::max(res, price - min_price);
            min_price = std::min(price, min_price);
        }

        return res;
    }
#endif
};

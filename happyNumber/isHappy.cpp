#include <unordered_set>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
    bool isHappy(int n)
    {
        int fast = n, slow = n;

        do
        {
            slow = bit_square_sum(slow);
            fast = bit_square_sum(fast);
            fast = bit_square_sum(fast);
        } while (slow != fast);

        return slow == 1;
    }

    int bit_square_sum(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }

        return sum;
    }
#endif

#if method2
    bool isHappy(int n)
    {
        std::unordered_set<int> s;

        while (1)
        {
            int sum = get_sum(n);

            if (sum == 1) return true;

            if (s.find(sum) != s.end()) return false;
            s.insert(sum);

            n = sum;
        }
    }

    int get_sum(int n)
    {
        int sum = 0;

        while (n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }

        return sum;
    }
#endif
};

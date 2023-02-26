#include <unordered_set>

#define method1 1
#define method2 0

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
#if method1
    bool hasCycle(ListNode *head)
    {
        std::unordered_set<ListNode*> seen;

        while (head != nullptr)
        {
            if (seen.count(head)) return true;

            seen.insert(head);
            head = head->next;
        }

        return false;
    }
#endif

#if method2
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr) return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
#endif
};

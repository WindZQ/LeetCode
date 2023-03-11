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
    ListNode *getIntersectionNode(ListNode* headA, ListNode *headB)
    {
        std::unordered_set<ListNode*> res;
        ListNode* temp = headA;

        while (temp != nullptr)
        {
            res.insert(temp);
            temp = temp->next;
        }
        temp = headB;

        while (temp != nullptr)
        {
            if (res.count(temp))
            {
                return temp;
            }

            temp = temp->next;
        }

        return nullptr;
    }
#endif

#if method2
    ListNode *getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *p_a = headA, *p_b = headB;
        while (p_a != p_b)
        {
            p_a = p_a == nullptr ? headB : p_a->next;
            p_b = p_b == nullptr ? headA : p_b->next;
        }

        return p_a;
    }
#endif
};

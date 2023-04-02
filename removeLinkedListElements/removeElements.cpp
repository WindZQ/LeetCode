
#define method1 1
#define method2 0

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
#if method1
    ListNode *removeElements(ListNode* head, int val)
    {
        if (head == nullptr) return head;

        head->next = removeElements(head->next, val);

        return head->val == val ? head->next : head;
    }
#endif

#if method2
    ListNode *removeElements(ListNode* head, int val)
    {
        struct ListNode* dumm_head = new ListNode(0, head);
        struct ListNode* temp = dumm_head;

        while (temp->next != nullptr)
        {
            if (temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }

        return dumm_head->next;
    }
#endif
};

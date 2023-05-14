#include <vector>

#define method1 1
#define method2 0
#define method3 0

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
#if method1
    bool isPalindrome(ListNode* head)
    {
        std::vector<int> res;

        while (head != nullptr)
        {
            res.emplace_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = res.size() - 1; i < j; ++i, --j)
        {
            if (res[i] != res[j]) return false;
        }

        return true;
    }
#endif

#if method2
    ListNode* front_pointer;
    bool isPalindrome(ListNode *head)
    {
        front_pointer = head;

        return recursively_check(head);
    }

    bool recursively_check(ListNode* current_node)
    {
        if (current_node != nullptr)
        {
            if (!recursively_check(current_node->next))
            {
                return false;
            }

            if (current_node->val != front_pointer->val)
            {
                return false;
            }

            front_pointer = front_pointer->next;
        }

        return true;
    }
#endif

#if method3
    bool isPalindrome(ListNode* head)
    {
        if (head == nullptr) return true;

        ListNode* fast = endof_first_half(head);
        ListNode* slow = reverse_list(fast->next);

        ListNode* p1 = head;
        ListNode* p2 = slow;
        bool result = true;

        while (result && p2 != nullptr)
        {
            if (p1->val != p2->val)
            {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        fast->next = reverse_list(slow);

        return result;
    }

    ListNode* reverse_list(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    ListNode* endof_first_half(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
#endif
};

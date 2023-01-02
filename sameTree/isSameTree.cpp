#include <queue>

#define method1 1
#define method2 0

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
#if method1
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
#endif

#if method2
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }

        std::queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty())
        {
            auto node1 = q1.front();
            q1.pop();
            auto node2 = q2.front();
            q2.pop();

            if (node1->val != node2->val)
            {
                return false;
            }

            auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
            if ((left1 == nullptr) ^ (left2 == nullptr))
            {
                return false;
            }

            if ((right1 == nullptr) ^ (right2 == nullptr))
            {
                return false;
            }

            if (left1 != nullptr)
            {
                q1.push(left1);
            }

            if (right1 != nullptr)
            {
                q1.push(right1);
            }

            if (left2 != nullptr)
            {
                q2.push(left2);
            }

            if (right2 != nullptr)
            {
                q2.push(right2);
            }
        }

        return q1.empty() && q2.empty();
    }
#endif
};

#include <vector>
#include <stack>

#define method1 1
#define method2 0
#define method3 0

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
#if method1
    void preorder(TreeNode *root, std::vector<int>& res)
    {
        if (root == nullptr) return ;

        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        preorder(root, res);

        return res;
    }
#endif

#if method2
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        if (root == nullptr) return res;

        std::stack<TreeNode*> s;
        TreeNode* node = root;

        while(!s.empty() || node != nullptr)
        {
            while (node != nullptr)
            {
                res.emplace_back(node->val);
                s.emplace(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            node = node->right;
        }

        return res;
    }
#endif

#if method3
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> res;

        if (root == nullptr) return res;

        TreeNode* p1 = root, *p2 = nullptr;

        while (p1 != nullptr)
        {
            p2 = p1->left;
            if (p2 != nullptr)
            {
                while (p2->right != nullptr && p2->right != p1)
                {
                    p2 = p2->right;
                }

                if (p2->right == nullptr)
                {
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                {
                    p2->right = nullptr;
                }
            }
            else
            {
                res.emplace_back(p1->val);
            }

            p1 = p1->right;
        }

        return res;
    }
#endif
};

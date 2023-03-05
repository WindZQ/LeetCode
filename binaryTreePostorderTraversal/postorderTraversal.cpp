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

class Soltion
{
public:
#if method1
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> res;
        postorder(root, res);

        return res;
    }

    void postorder(TreeNode* root, std::vector<int>& res)
    {
        if (root == nullptr) return;

        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
#endif

#if method2
    std::vector<int> postorderTraversal(TreeNode* root)
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
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                {
                    p2->right = nullptr;
                    add_path(res, p1->left);
                }
            }

            p1 = p1->right;
        }
        add_path(res, root);

        return res;
    }

    void add_path(std::vector<int>& v, TreeNode* node)
    {
        int count = 0;
        while (node != nullptr)
        {
            ++count;
            v.emplace_back(node->val);
            node = node->right;
        }

        std::reverse(v.end() - count, v.end());
    }
#endif

#if method3
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> res;

        if (root == nullptr) return res;

        std::stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        while (root != nullptr || !s.empty())
        {
            while (root != nullptr)
            {
                s.emplace(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            if (root->right == nullptr || root->right == pre)
            {
                res.emplace_back(root->val);
                pre = root;
                root = nullptr;
            }
            else
            {
                s.emplace(root);
                root = root->right;
            }
        }

        return res;
    }
#endif
};

#include <vector>
#include <stack>

#define method1 1
#define method2 0
#define method3 0

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
    void inorder(TreeNode *root, std::vector<int> & res)
    {
        if (!root) return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        inorder(root, res);
        return res;
    }
#endif

#if method2
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        std::stack<TreeNode*> st;

        while (root != nullptr || !st.empty())
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;
    }
#endif

#if method3
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        TreeNode* pre = nullptr;

        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                pre = root->left;
                while (pre->right != nullptr && pre->right != root)
                {
                    pre = pre->right;
                }

                if (pre->right == nullptr)
                {
                    pre->right = root;
                    root = root->left;
                }
                else
                {
                    res.push_back(root->val);
                    pre->right = nullptr;
                    root = root->right;
                }
            }
            else
            {
                res.push_back(root->val);
                root = root->right;
            }
        }

        return res;
    }
#endif
};

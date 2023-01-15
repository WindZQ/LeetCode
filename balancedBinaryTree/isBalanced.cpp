#include <algorithm>

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
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return std::abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }

    int height(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return std::max(height(root->left), height(root->right)) + 1;
        }
    }
#endif

#if method2
    bool isBalanced(TreeNode *root)
    {
        return height(root) >= 0;
    }

    int height(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);

        if (left_height == -1 || right_height == -1 || std::abs(left_height - right_height) > 1)
        {
            return -1;
        }
        else
        {
            return std::max(left_height, right_height) + 1;
        }
    }
#endif
};

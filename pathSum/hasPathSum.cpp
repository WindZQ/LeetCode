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
    TreeNode(int x, TreeNode *left, TreeNode * right) : val(x), left(left), right(right) {}
};


class Solution
{
public:
#if method1
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr) return false;

        std::queue<TreeNode*> node;
        std::queue<int> val;

        node.push(root);
        val.push(root->val);

        while (!node.empty())
        {
            TreeNode *now = node.front();
            int temp = val.front();

            node.pop();
            val.pop();

            if (now->left == nullptr && now->right == nullptr)
            {
                if (temp == targetSum) return true;
                continue;
            }

            if (now->left != nullptr)
            {
                node.push(now->left);
                val.push(now->left->val + temp);
            }

            if (now->right != nullptr)
            {
                node.push(now->right);
                val.push(now->right->val + temp);
            }
        }

        return false;
    }
#endif

#if method2
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr)
        {
            return targetSum == root->val;
        }

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
#endif
};

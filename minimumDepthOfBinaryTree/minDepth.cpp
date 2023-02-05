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
    int minDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;

        if (root->left == nullptr && root->right == nullptr) return 1;

        int min_depth = INT_MAX;
        if (root->left != nullptr)
        {
            min_depth = std::min(minDepth(root->left), min_depth);
        }

        if (root->right != nullptr)
        {
            min_depth = std::min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
#endif

#if method2
    int minDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;

        std::queue<std::pair<TreeNode*, int>> q;
        q.emplace(root, 1);

        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int depth = q.front().second;
            q.pop();

            if (node->left == nullptr && node->right == nullptr) return depth;

            if (node->left != nullptr)
            {
                q.emplace(node->left, depth + 1);
            }

            if (node->right != nullptr)
            {
                q.emplace(node->right, depth + 1);
            }
        }

        return 0;
    }
#endif
};

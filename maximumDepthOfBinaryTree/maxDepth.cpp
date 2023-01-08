#include <queue>
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
#endif

#if method2
    int maxDepth(TreeNode *root)
    {
        std::queue<TreeNode*> q;
        int res = 0;

        if (root == nullptr) return 0;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            while (size > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                size -= 1;
            }

            res += 1;
        }

        return res;
    }
#endif
};

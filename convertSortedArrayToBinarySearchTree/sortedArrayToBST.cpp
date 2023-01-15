#include <vector>

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(std::vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }
#endif

#if method2
    TreeNode *sortedArrayToBST(std::vector<int>& nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(std::vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;

        int mid = (left + right + 1) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }
#endif

#if method3
    TreeNode *sortedArrayToBST(std::vector<int>& nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(std::vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;

        int mid = (left + right + rand() % 2) / 2;

        TreeNode* root = new TreeNode(num[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }
#endif
};

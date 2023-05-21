#include <vector>
#include <string>
#include <queue>

#define method1 1
#define method2 0

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
    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> res;
        construct_path(root, "", res);

        return res;
    }

    void construct_path(TreeNode* root, std::string path, std::vector<std::string>& paths)
    {
        if (root != nullptr)
        {
            path += std::to_string(root->val);
            if (root->left == nullptr && root->right == nullptr)
            {
                paths.push_back(path);
            }
            else
            {
                path += "->";
                construct_path(root->left, path, paths);
                construct_path(root->right, path, paths);
            }
        }
    }
#endif

#if method2
    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        std::vector<std::string> paths;
        if (root == nullptr) return paths;

        std::queue<TreeNode*> node_queue;
        std::queue<std::string> path_queue;
        node_queue.push(root);
        path_queue.push(std::to_string(root->val));

        while (!node_queue.empty())
        {
            TreeNode* node = node_queue.front();
            std::string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();

            if (node->left == nullptr && node->right == nullptr)
            {
                paths.push_back(path);
            }
            else
            {
                if (node->left != nullptr)
                {
                    node_queue.push(node->left);
                    path_queue.push(path + "->" + std::to_string(node->left->val));
                }

                if (node->right != nullptr)
                {
                    node_queue.push(node->right);
                    path_queue.push(path + "->" + std::to_string(node->right->val));
                }
            }
        }

        return paths;
    }
#endif
};

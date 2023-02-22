#include "leetcode_header.h"

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (root == NULL)
        {
            return ret;
        }

        stack<TreeNode *> s;
        s.push(root);
        bool l_to_r = true;
        while (s.size() > 0)
        {
            size_t size = s.size();

            stack<TreeNode *> next_s;
            vector<int> layer;
            for (size_t i = 0; i < size; i++)
            {
                TreeNode *node = s.top();
                s.pop();
                layer.push_back(node->val);
                if (l_to_r)
                {
                    if (node->left != NULL)
                        next_s.push(node->left);
                    if (node->right != NULL)
                        next_s.push(node->right);
                }
                else
                {
                    if (node->right != NULL)
                        next_s.push(node->right);
                    if (node->left != NULL)
                        next_s.push(node->left);
                }
            }

            s = next_s;
            ret.push_back(layer);
            l_to_r = !l_to_r;
        }

        return ret;
    }
};
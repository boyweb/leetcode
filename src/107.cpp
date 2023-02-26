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
private:
    int len;
    queue<TreeNode *> m_queue;

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret;

        if (root == NULL)
        {
            return {};
        }

        m_queue.push(root);
        len = 1;

        while (len > 0)
        {
            vector<int> layer;
            int next_len = 0;
            for (size_t i = 0; i < len; i++)
            {
                TreeNode *node = m_queue.front();
                m_queue.pop();
                layer.push_back(node->val);
                if (node->left != NULL)
                {
                    m_queue.push(node->left);
                    next_len++;
                }
                if (node->right != NULL)
                {
                    m_queue.push(node->right);
                    next_len++;
                }
            }
            ret.push_back(layer);
            len = next_len;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
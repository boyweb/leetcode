#include "leetcode_header.h"

class Solution
{
    vector<vector<int>> m_ret;
    vector<int> m_nums;
    int m_size;

    vector<bool> m_used;
    vector<int> m_current;

    void next(int current)
    {
        for (int i = 0; i < m_size; i++)
        {
            if (!m_used[i])
            {
                m_current[current] = m_nums[i];

                if (current == m_size - 1)
                {
                    m_ret.push_back(m_current);
                }
                else
                {
                    m_used[i] = true;
                    next(current + 1);
                    m_used[i] = false;
                }
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        m_nums = nums;
        m_size = nums.size();

        for (int i = 0; i < m_size; i++)
        {
            m_used.push_back(false);
            m_current.push_back(0);
        }

        next(0);

        return m_ret;
    }
};
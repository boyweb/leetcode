#include "leetcode_header.h"

class Solution
{
private:
    vector<vector<int>> m_ret;
    vector<int> m_list;

    vector<int> m_candidates;
    int m_target;

    void check(int idx, int size, int current)
    {
        for (int i = idx; i < m_candidates.size(); i++)
        {
            if (current + m_candidates[i] < m_target)
            {
                m_list.push_back(m_candidates[i]);
                check(i, size + 1, current + m_candidates[i]);
                m_list.erase(m_list.begin() + size);
            }
            else if (current + m_candidates[i] == m_target)
            {
                m_list.push_back(m_candidates[i]);
                m_ret.push_back(m_list);
                m_list.erase(m_list.begin() + size);
                break;
            }
            else
            {
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        m_candidates = candidates;
        m_target = target;

        sort(m_candidates.begin(), m_candidates.end());
        check(0, 0, 0);

        return m_ret;
    }
};
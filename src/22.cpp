#include "leetcode_header.h"

class Solution
{
private:
    int m_target;
    vector<string> m_ret;
    void next(string current, int n, int value)
    {
        if (n == m_target)
        {
            if (value > 0)
            {
                next(current + ")", n, value - 1);
            }
            else
            {
                m_ret.push_back(current);
            }
        }
        else
        {
            next(current + "(", n + 1, value + 1);
            if (value > 0)
            {
                next(current + ")", n, value - 1);
            }
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        m_target = n;
        next("", 0, 0);

        return m_ret;
    }
};
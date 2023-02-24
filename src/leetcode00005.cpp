#include "leetcode_header.h"

class Solution
{
private:
    char m_str_expanded[3000];
    int m_str_expanded_len;
    int m_max_len = 0;
    int m_max_index;

    void expand(string s)
    {
        int len = s.length();
        for (size_t i = 0; i < len; i++)
        {
            m_str_expanded[i * 2] = '#';
            m_str_expanded[i * 2 + 1] = s[i];
        }
        m_str_expanded[len * 2] = '#';
        m_str_expanded_len = len * 2 + 1;
    }

    void findPalindrome(int i)
    {
        int size = 1;
        while (1)
        {
            int left = i - size;
            int right = i + size;
            if (left >= 0 && right < m_str_expanded_len && m_str_expanded[left] == m_str_expanded[right])
            {
                size++;
            }
            else
            {
                break;
            }
        }

        if (size > m_max_len)
        {
            m_max_index = i;
            m_max_len = size;
        }
    }

public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }

        expand(s);
        for (size_t i = 0; i < m_str_expanded_len; i++)
        {
            findPalindrome(i);
        }

        int l = m_max_index - (m_max_len - 1), r = m_max_index + (m_max_len - 1);
        string ret = "";
        for (size_t i = l; i <= r; i++)
        {
            if (m_str_expanded[i] == '#')
                continue;
            ret.push_back(m_str_expanded[i]);
        }

        return ret;
    }
};
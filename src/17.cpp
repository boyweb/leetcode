#include "leetcode_header.h"

class Solution
{
    vector<vector<string>> list = {
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"},
        {"j", "k", "l"},
        {"m", "n", "o"},
        {"p", "q", "r", "s"},
        {"t", "u", "v"},
        {"w", "x", "y", "z"}};

    vector<string> m_ret;
    void next(string digis, int idx, string current)
    {
        int idx_list = digis[idx] - '2';
        if (idx < digis.length() - 1)
        {
            for (auto c : list[idx_list])
            {
                next(digis, idx + 1, current + c);
            }
        }
        else
        {
            for (auto c : list[idx_list])
            {
                m_ret.push_back(current + c);
            }
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};

        next(digits, 0, "");
        return m_ret;
    }
};
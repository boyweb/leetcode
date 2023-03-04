#include "leetcode_header.h"

class Solution
{
private:
    unordered_map<string, vector<string>> m_list;

    string generateKey(string str)
    {
        int cnt[26] = {0};
        for (string::iterator it = str.begin(); it < str.end(); it++)
        {
            cnt[*it - 'a']++;
        }

        stringstream key_stream;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == 0)
            {
                continue;
            }

            key_stream << (char)('a' + i) << cnt[i];
        }

        return key_stream.str();
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return {};
        }

        for (auto str : strs)
        {
            string value = generateKey(str);
            if (m_list.find(value) != m_list.end())
            {
                m_list[value].push_back(str);
            }
            else
            {
                vector<string> list = {str};
                m_list.emplace(value, list);
            }
        }

        vector<vector<string>> ret;
        for (auto list : m_list)
        {
            ret.push_back(list.second);
        }

        return ret;
    }
};
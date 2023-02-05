#include "leetcode_header.h"

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.length();
        if (size < 2)
        {
            return s;
        }
        

        bool p[size][size] = {false};
        for (int i = 0; i < size; i++)
        {
            p[i][i] = true;
        }

    }
};
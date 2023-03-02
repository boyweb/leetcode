#include "leetcode_header.h"

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int size = s.length();
        if (size == 0)
        {
            return 0;
        }
        int f[100000] = {0};
        int max = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            if (s[i] == ')' || i + 1 > size)
            {
                continue;
            }

            if (s[i + 1] == ')')
            {
                f[i] = 2;
                if (i + 2 < size)
                {
                    f[i] += f[i + 2];
                }
            }
            else
            {
                if (f[i + 1] > 0)
                {
                    if (i + 1 + f[i + 1] < size && s[i + 1 + f[i + 1]] == ')')
                    {
                        f[i] = f[i + 1] + 2;
                        if (i + f[i] < size)
                        {
                            f[i] += f[i + f[i]];
                        }
                    }
                }
            }

            if (f[i] > max)
            {
                max = f[i];
            }
        }

        return max;
    }
};
#include "leetcode_header.h"

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;

        int t[n];
        t[0] = 1;
        t[1] = 2;
        for (int i = 2; i < n; i++)
        {
            t[i] = t[i - 1] + t[i - 2];
        }

        return t[n - 1];
    }
};
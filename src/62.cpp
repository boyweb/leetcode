#include "leetcode_header.h"

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int ret[m][n];
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    ret[i][j] = 1;
                }
                else
                {
                    ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
                }
            }
        }

        return ret[m - 1][n - 1];
    }
};
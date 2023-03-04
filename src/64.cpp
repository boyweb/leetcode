#include "leetcode_header.h"

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int value[m][n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    value[i][j] = grid[i][j] + (j > 0 ? value[i][j - 1] : 0);
                }
                else if (j == 0)
                {
                    value[i][j] = grid[i][j] + (i > 0 ? value[i - 1][j] : 0);
                }
                else
                {
                    value[i][j] = grid[i][j] + min(value[i - 1][j], value[i][j - 1]);
                }
            }
        }

        return value[m - 1][n - 1];
    }
};
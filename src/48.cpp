#include "leetcode_header.h"

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int last_idx = n - 1;
        int x = n % 2 == 0 ? n / 2 - 1 : n / 2;
        int y = n / 2 - 1;

        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= y; j++)
            {
                int tx = i, ty = j;
                int temp = matrix[tx][ty];
                for (int k = 0; k < 3; k++)
                {
                    int nx = last_idx - ty;
                    int ny = tx;
                    matrix[tx][ty] = matrix[nx][ny];
                    tx = nx;
                    ty = ny;
                }
                matrix[tx][ty] = temp;
            }
        }
    }
};
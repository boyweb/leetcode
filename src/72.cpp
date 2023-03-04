#include "leetcode_header.h"

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();

        if (m == 0)
        {
            return n;
        }
        if (n == 0)
        {
            return m;
        }

        bool same[m + 1][n + 1];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (word1[i] == word2[j])
                {
                    same[i][j] = true;
                }
                else
                {
                    same[i][j] = false;
                }
            }
        }

        int dist[m + 1][n + 1];
        dist[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            dist[i][0] = dist[i - 1][0] + 1;
        }
        for (int i = 1; i <= n; i++)
        {
            dist[0][i] = dist[0][i - 1] + 1;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int corner = dist[i - 1][j - 1] + (same[i - 1][j - 1] ? 0 : 1);
                int up = dist[i - 1][j] + 1;
                int left = dist[i][j - 1] + 1;

                dist[i][j] = min(min(up, left), corner);
            }
        }

        return dist[m][n];
    }
};
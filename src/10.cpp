#include "leetcode_header.h"

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        s = " " + s;
        p = " " + p;
        int m = s.size(), n = p.size();

        bool dp[35];
        memset(dp, false, sizeof dp);
        dp[0] = true;
        for (int i = 2; i < n; i++)
        {
            if (p[i] == '*')
            {
                dp[i] = dp[i - 2];
            }
        }

        for (int i = 1; i < m; i++)
        {

            bool dp2[35];
            memset(dp2, false, sizeof dp2);

            for (int j = 1; j < n; j++)
            {
                if (s[i] == p[j] || p[j] == '.')
                {
                    dp2[j] = dp[j - 1];
                }
                else if (p[j] == '*')
                {
                    if (p[j - 1] != s[i] && p[j - 1] != '.')
                    {
                        dp2[j] = dp2[j - 2];
                    }
                    else
                    {
                        dp2[j] = dp2[j - 2] | dp[j];
                    }
                }
            }
            memcpy(dp, dp2, sizeof dp);
        }

        return dp[n - 1];
    }
};
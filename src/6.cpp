#include "leetcode_header.h"

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int size = s.length();
        if (size <= 2 || numRows == 1)
        {
            return s;
        }

        string target;

        int sep = (numRows - 1) * 2;
        int baseSep = sep;

        for (int i = 0; i < numRows; i++)
        {
            if (i >= size)
            {
                break;
            }
            
            int idx = i;

            int curSep = baseSep;
            if (curSep == 0)
            {
                curSep = sep - curSep;
            }

            while (true)
            {
                target += s[idx];
                idx += curSep;

                if (curSep != sep)
                {
                    curSep = sep - curSep;
                }

                if (idx >= size)
                {
                    break;
                }
            }

            baseSep -= 2;
        }

        return target;
    }
};
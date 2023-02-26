#include "leetcode_header.h"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;

        int max = 0;

        while (i != j)
        {
            int size = (j - i) * min(height[i], height[j]);
            if (size > max)
            {
                max = size;
            }

            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return max;
    }
};
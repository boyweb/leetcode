#include "leetcode_header.h"

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0)
        {
            return 0;
        }

        int sum = 0;
        int left = 0, right = height.size() - 1;
        int left_max = height[left];
        int right_max = height[right];

        while (left != right)
        {
            if (height[left] <= height[right])
            {
                left++;
                if (height[left] > left_max)
                {
                    left_max = height[left];
                }
                else
                {
                    int min_side = min(left_max, right_max);
                    if (height[left] < min_side)
                    {
                        sum += (min_side - height[left]);
                    }
                }
            }
            else
            {
                right--;
                if (height[right] > right_max)
                {
                    right_max = height[right];
                }
                else
                {
                    int min_side = min(left_max, right_max);
                    if (height[right] < min_side)
                    {
                        sum += (min_side - height[right]);
                    }
                }
            }
        }

        return sum;
    }
};
#include "leetcode_header.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = INT32_MIN;
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i - 1] > 0)
            {
                nums[i] += nums[i - 1];
            }

            if (nums[i] > max)
            {
                max = nums[i];
            }
        }

        return max;
    }
};
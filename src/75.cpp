#include "leetcode_header.h"

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int p = 0;
        while (p <= right)
        {
            if (nums[p] == 0)
            {
                nums[p] = nums[left];
                nums[left++] = 0;
                p++;
            }
            else if (nums[p] == 2)
            {
                nums[p] = nums[right];
                nums[right--] = 2;
            }
            else
            {
                p++;
            }
        }
    }
};
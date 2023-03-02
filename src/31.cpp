#include "leetcode_header.h"

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
        {
            return;
        }

        int replace_idx = -1;
        for (int i = size - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                replace_idx = i;
                break;
            }
        }

        if (replace_idx < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {

            int min = 1000;
            int min_idx = -1;
            for (int i = replace_idx + 1; i < size; i++)
            {
                if (nums[i] > nums[replace_idx] && nums[i] < min)
                {
                    min = nums[i];
                    min_idx = i;
                }
            }

            int temp = nums[replace_idx];
            nums[replace_idx] = nums[min_idx];
            nums[min_idx] = temp;

            sort(nums.begin() + replace_idx + 1, nums.end());
        }
    }
};
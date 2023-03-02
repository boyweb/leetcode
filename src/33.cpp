#include "leetcode_header.h"

class Solution
{
    int specialSearch(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
        {
            return -1;
        }

        int mid = (left + right) / 2;
        if (target == nums[mid])
        {
            return mid;
        }

        if (nums[left] <= nums[mid] && nums[mid] > nums[right])
        {
            if (target > nums[mid])
            {
                return specialSearch(nums, target, mid + 1, right);
            }
            else if (target <= nums[right])
            {
                return specialSearch(nums, target, mid + 1, right);
            }
            else
            {
                return specialSearch(nums, target, left, mid - 1);
            }
        }
        else if (nums[left] > nums[mid] && nums[mid] <= nums[right])
        {
            if (target < nums[mid])
            {
                return specialSearch(nums, target, left, mid - 1);
            }
            else if (target >= nums[left])
            {
                return specialSearch(nums, target, left, mid - 1);
            }
            else
            {
                return specialSearch(nums, target, mid + 1, right);
            }
        }
        else
        {
            if (target > nums[mid])
            {
                return specialSearch(nums, target, mid + 1, right);
            }
            else
            {
                return specialSearch(nums, target, left, mid - 1);
            }
        }
    }

public:
    int search(vector<int> &nums, int target)
    {
        return specialSearch(nums, target, 0, nums.size() - 1);
    }
};
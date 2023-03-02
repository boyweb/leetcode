#include "leetcode_header.h"

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int size = nums.size();
        if (size == 0)
        {
            return {-1, -1};
        }

        int left = -1, right = -1;
        int ll = 0, rl = 0, lr = size - 1, rr = size - 1;

        while (ll <= lr)
        {
            int mid = (ll + lr) / 2;
            if (target == nums[mid])
            {
                if (mid - 1 >= 0 && nums[mid - 1] == target)
                {
                    lr = mid - 1;
                }
                else
                {
                    left = mid;
                    break;
                }
            }
            else if (target < nums[mid])
            {
                lr = mid - 1;
            }
            else
            {
                ll = mid + 1;
            }
        }

        if (left == -1)
        {
            return {-1, -1};
        }

        while (rl <= rr)
        {
            int mid = (rl + rr) / 2;
            if (target == nums[mid])
            {
                if (mid + 1 < size && nums[mid + 1] == target)
                {
                    rl = mid + 1;
                }
                else
                {
                    right = mid;
                    break;
                }
            }
            else if (target < nums[mid])
            {
                rr = mid - 1;
            }
            else
            {
                rl = mid + 1;
            }
        }

        return {left, right};
    }
};
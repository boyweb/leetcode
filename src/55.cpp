#include "leetcode_header.h"

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();
        int max_reach = 0;
        for (int i = 0; i < size; i++)
        {
            if (i > max_reach)
            {
                return false;
            }

            if (i + nums[i] >= max_reach)
            {
                max_reach = i + nums[i];
                if (max_reach >= size - 1)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
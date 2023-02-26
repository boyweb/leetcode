#include "leetcode_header.h"

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        vector<int>::iterator i, j, k;
        i = nums.begin();

        while (i < nums.end() - 2)
        {
            if (*i > 0)
            {
                break;
            }

            j = i + 1;
            k = nums.end() - 1;
            while (j < k)
            {
                int value = *i + *j + *k;
                if (value == 0)
                {
                    ret.push_back({*i, *j, *k});
                    do
                    {
                        j++;
                    } while (j < nums.end() && *j == *(j - 1));
                    do
                    {
                        k--;
                    } while (k >= nums.begin() && *k == *(k + 1));
                }
                else if (value < 0)
                {
                    do
                    {
                        j++;
                    } while (j < nums.end() && *j == *(j - 1));
                }
                else if (value > 0)
                {
                    do
                    {
                        k--;
                    } while (k >= nums.begin() && *k == *(k + 1));
                }
            }

            do
            {
                i++;
            } while (i < nums.end() && *i == *(i - 1));
        }

        return ret;
    }
};
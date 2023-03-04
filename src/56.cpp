#include "leetcode_header.h"

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
        {
            return intervals;
        }

        vector<vector<int>> ret;
        int size = 0;

        sort(intervals.begin(), intervals.end());

        bool flag = false;
        for (auto interval : intervals)
        {
            if (!flag)
            {
                ret.push_back(interval);
                size++;
                flag = true;
            }
            else
            {
                if (interval[0] <= ret[size - 1][1])
                {
                    if (interval[1] > ret[size - 1][1])
                    {

                        ret[size - 1][1] = interval[1];
                    }
                }
                else
                {
                    ret.push_back(interval);
                    size++;
                }
            }
        }

        return ret;
    }
};
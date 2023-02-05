#include "leetcode_header.h"

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> num_map;
		vector<int> ret;
		int i = 0;
		for (auto num : nums) {
			map<int, int>::iterator iter;
			if (iter = num_map.find(target - num), iter != num_map.end()) {
				ret.push_back(iter->second);
				ret.push_back(i);
				break;
			}

			num_map[num] = i;
			i++;
		}

		return ret;
	}
};
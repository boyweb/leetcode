#include "leetcode_header.h"

#define LEETCODE00010

#ifdef LEETCODE00001
#include "leetcode00001.cpp"
#endif

#ifdef LEETCODE00002
#include "leetcode00002.cpp"
#endif

#ifdef LEETCODE00005
#include "leetcode00005.cpp"
#endif

#ifdef LEETCODE00010
#include "leetcode00010.cpp"
#endif

#ifdef LEETCODE00006
#include "leetcode00006.cpp"
#endif

#ifdef LEETCODE00146
#include "leetcode00146.cpp"
#endif

#ifdef LEETCODE00206
#include "leetcode00206.cpp"
#endif

#ifdef LEETCODE00215
#include "leetcode00215.cpp"
#endif

int main()
{

#ifdef LEETCODE00001
    Solution solution;

    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    auto ret = solution.twoSum(nums, target);

    for (auto i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
#endif

#ifdef LEETCODE00002
    Solution solution;
#endif

#ifdef LEETCODE00005
    Solution solution;

    cout << solution.longestPalindrome("aacaa") << endl;
#endif

#ifdef LEETCODE00010
    Solution solution;

    cout << solution.isMatch("bbbba", ".*a*a") << endl;
#endif

#ifdef LEETCODE00006
    Solution solution;

    cout << solution.convert("ABC", 4) << endl;
#endif

#ifdef LEETCODE00146
    LRUCache *cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;
    cache->put(3, 3);
    cout << cache->get(2) << endl;
    cache->put(4, 4);
    cout << cache->get(1) << endl;
    cout << cache->get(3) << endl;
    cout << cache->get(4) << endl;
#endif

#ifdef LEETCODE00206
    Solution solution;
#endif

#ifdef LEETCODE00215
    Solution solution;

    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << solution.findKthLargest(nums, 4) << endl;
#endif

    return 0;
}
#include "leetcode_header.h"

#define STRINGIFY(X) STRINGIFY2(X)
#define STRINGIFY2(X) #X
#define CAT(X, Y) CAT2(X, Y)
#define CAT2(X, Y) X##Y
#define CAT_2 CAT
#define CAT_3(X, Y, Z) CAT(X, CAT(Y, Z))

#define LEETCODE 19

#define LEET_CODE_INCLUDE(NUMBER) STRINGIFY(CAT(NUMBER, .cpp))

#include LEET_CODE_INCLUDE(LEETCODE)

int main()
{

#if LEETCODE == 1
    Solution solution;

    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    auto ret = solution.twoSum(nums, target);

    for (auto i : ret)
    {
        cout << i << " ";
    }
    cout << endl;
#elif LEETCODE == 2
    Solution solution;
#elif LEETCODE == 5
    Solution solution;

    cout << solution.longestPalindrome("aacaa") << endl;
#elif LEETCODE == 6
    Solution solution;

    cout << solution.convert("ABC", 4) << endl;
#elif LEETCODE == 10
    Solution solution;

    cout << solution.isMatch("bbbba", ".*a*a") << endl;
#elif LEETCODE == 15
    Solution solution;
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {1, -1, -1, 0};
    // vector<int> nums = {1, 1, -2};
    vector<int> nums = {0, 0, 0};

    auto ret = solution.threeSum(nums);
    for (auto i : ret)
    {
        printf("[%d, %d, %d]\n", i[0], i[1], i[2]);
    }
#elif LEETCODE == 17
    Solution solution;
    auto ret = solution.letterCombinations("7979");
    for (auto i : ret)
    {
        cout << i << endl;
    }
#elif LEETCODE == 19
    Solution solution;

    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, NULL)))));
    // ListNode *head = new ListNode(1, NULL);

    auto ret = solution.removeNthFromEnd(head, 1);
    while (ret != NULL)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }

#elif LEETCODE == 146
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
#elif LEETCODE == 206
    Solution solution;
#elif LEETCODE == 215
    Solution solution;

    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << solution.findKthLargest(nums, 4) << endl;
#endif

    return 0;
}
#include "leetcode_header.h"

#define STRINGIFY(X) STRINGIFY2(X)
#define STRINGIFY2(X) #X
#define CAT(X, Y) CAT2(X, Y)
#define CAT2(X, Y) X##Y
#define CAT_2 CAT
#define CAT_3(X, Y, Z) CAT(X, CAT(Y, Z))

#define LEETCODE 42

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

#elif LEETCODE == 20
    Solution solution;
    cout << solution.isValid("]") << endl;
#elif LEETCODE == 21
    Solution solution;

    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4, NULL)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4, NULL)));

    auto ret = solution.mergeTwoLists(list1, list2);
    while (ret != NULL)
    {
        cout << ret->val << endl;
        ret = ret->next;
    }
#elif LEETCODE == 22
    Solution solution;
    auto ret = solution.generateParenthesis(5);
    for (auto i : ret)
    {
        cout << i << endl;
    }
#elif LEETCODE == 23
    Solution solution;
    vector<ListNode *> lists = {
        // NULL,
        // new ListNode(1, new ListNode(4, new ListNode(5, NULL))),
        // new ListNode(1, new ListNode(3, new ListNode(4, NULL))),
        // new ListNode(2, new ListNode(6, NULL)),
    };

    auto ret = solution.mergeKLists(lists);
    while (ret != NULL)
    {
        cout << ret->val << ", ";
        ret = ret->next;
    }
    cout << endl;
#elif LEETCODE == 31
    Solution solution;

    // vector<int> nums = {1, 9, 5, 8, 7, 3};
    // vector<int> nums = {1, 2, 3};
    // vector<int> nums = {3, 2, 1};
    // vector<int> nums = {1, 1, 5};
    vector<int> nums = {1, 3, 2};
    solution.nextPermutation(nums);
    for (auto i : nums)
    {
        cout << i << ", ";
    }
    cout << endl;
#elif LEETCODE == 32
    Solution solution;

    // cout << solution.longestValidParentheses(")()())") << endl;
    // cout << solution.longestValidParentheses("(()") << endl;
    cout << solution.longestValidParentheses("(())()(()())(((()(())") << endl;
#elif LEETCODE == 33
    Solution solution;

    vector<int> nums = {3, 1};
    cout << solution.search(nums, 1) << endl;
#elif LEETCODE == 34
    Solution solution;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto ret = solution.searchRange(nums, 7);
    cout << ret[0] << "," << ret[1] << endl;
#elif LEETCODE == 39
    Solution solution;

    // vector<int> candidates = {2, 3, 6, 7};
    // int target = 7;
    // vector<int> candidates = {2, 3, 5};
    // int target = 8;
    vector<int> candidates = {8, 7, 4, 3};
    int target = 11;

    auto ret = solution.combinationSum(candidates, target);
    for (auto l : ret)
    {
        for (auto num : l)
        {
            cout << num << ',';
        }
        cout << endl;
    }

#elif LEETCODE == 42
    Solution solution;
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height = {4, 2, 0, 3, 2, 5};

    cout << solution.trap(height) << endl;
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
#include "leetcode_header.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(-1, NULL);
        ListNode *first = head;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                head->next = list1;
                head = head->next;

                list1 = list1->next;
            }
            else
            {
                head->next = list2;
                head = head->next;

                list2 = list2->next;
            }
        }

        if (list1 != NULL)
        {
            head->next = list1;
        }
        else if (list2 != NULL)
        {
            head->next = list2;
        }

        return first->next;
    }
};
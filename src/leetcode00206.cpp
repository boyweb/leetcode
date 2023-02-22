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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = head;
        ListNode *current = head->next;
        prev->next = NULL;
        while (1)
        {
            ListNode *temp = current->next;
            current->next = prev;

            if (temp == NULL)
            {
                break;
            }

            prev = current;
            current = temp;
        }

        return current;
    }
};
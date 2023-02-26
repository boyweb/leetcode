#include "leetcode_header.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }

        ListNode *q, *s;
        q = head;
        s = head;

        while (true)
        {
            if (q->next == NULL)
            {
                return false;
            }
            if (q->next->next == NULL)
            {
                return false;
            }

            q = q->next->next;
            s = s->next;

            if (q == s)
            {
                break;
            }
        }

        return true;
    }
};
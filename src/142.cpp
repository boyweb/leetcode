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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *p = new ListNode(-1);
        p->next = head;
        ListNode *q = p, *s = p;

        while (true)
        {
            if (q->next == NULL)
            {
                return NULL;
            }
            if (q->next->next == NULL)
            {
                return NULL;
            }

            q = q->next->next;
            s = s->next;

            if (q == s)
            {
                break;
            }
        }

        s = p;

        while (s != q)
        {
            s = s->next;
            q = q->next;
        }

        return s;
    }
};
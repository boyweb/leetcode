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
    vector<ListNode *> m_vector;

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head;
        while (p != NULL)
        {
            m_vector.push_back(p);
            p = p->next;
        }
        int size = m_vector.size();

        m_vector.push_back(NULL);

        if (n == size)
            return m_vector[1];

        m_vector[size - n - 1]->next = m_vector[size - n + 1];

        return m_vector[0];
    }
};
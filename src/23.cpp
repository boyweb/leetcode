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
private:
    ListNode *m_heap[20000];
    int m_size;

    void swap(int ia, int ib)
    {
        ListNode *temp = m_heap[ia];
        m_heap[ia] = m_heap[ib];
        m_heap[ib] = temp;
    }

    void shiftNode(int idx)
    {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;

        if (left >= m_size)
        {
            return;
        }
        else if (right < m_size && m_heap[right]->val < m_heap[idx]->val && m_heap[right]->val < m_heap[left]->val)
        {
            swap(idx, right);
            shiftNode(right);
        }
        else if (m_heap[left]->val < m_heap[idx]->val)
        {
            swap(idx, left);
            shiftNode(left);
        }
    }

    void createHeap()
    {
        for (int i = m_size / 2; i >= 0; i--)
        {
            shiftNode(i);
        }
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode(-1, NULL);
        ListNode *first = head;

        m_size = 0;
        for (auto l : lists)
        {
            if (l != NULL)
            {
                m_heap[m_size] = l;
                m_size++;
            }
        }

        if (m_size > 0)
        {
            createHeap();
        }

        while (m_size > 0)
        {
            head->next = m_heap[0];
            head = head->next;
            if (m_size == 1)
            {
                break;
            }

            m_heap[0] = m_heap[0]->next;

            if (m_heap[0] == NULL)
            {
                m_heap[0] = m_heap[m_size - 1];
                m_size--;
                shiftNode(0);
            }
            else
            {
                shiftNode(0);
            }
        }

        return first->next;
    }
};
#include "leetcode_header.h"

class Solution
{
private:
    vector<int> m_heap;
    int m_heap_size = 0;
    void swap(int i1, int i2)
    {
        int temp = m_heap[i1];
        m_heap[i1] = m_heap[i2];
        m_heap[i2] = temp;
    }

    void shiftNode(int i)
    {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        if (left >= m_heap_size)
        {
            return;
        }
        if (right < m_heap_size && m_heap[right] < m_heap[i] && m_heap[right] < m_heap[left])
        {
            swap(i, right);
            shiftNode(right);
            return;
        }
        if (m_heap[left] < m_heap[i])
        {
            swap(i, left);
            shiftNode(left);
            return;
        }
    }

    void heapCreate()
    {
        for (int i = m_heap_size / 2; i >= 0; i--)
        {
            shiftNode(i);
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int size = nums.size();
        bool create = true;

        for (size_t i = 0; i < size; i++)
        {
            if (create)
            {
                m_heap.push_back(nums[i]);
                m_heap_size++;
                if (m_heap_size == k)
                {
                    heapCreate();
                    create = false;
                }
            }
            else
            {
                if (nums[i] > m_heap[0])
                {
                    m_heap[0] = nums[i];
                    shiftNode(0);
                }
            }
        }

        return m_heap[0];
    }
};
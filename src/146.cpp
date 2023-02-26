#include "leetcode_header.h"

typedef struct LRUNode
{
    LRUNode *prev;
    int key;
    int val;
    LRUNode *next;
    LRUNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    LRUNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
} LRUNode;

class LRUCache
{
private:
    LRUNode *m_head;
    LRUNode *m_tail;

    int m_size;
    int m_capacity;

    unordered_map<int, LRUNode *> m_cache;

    void removeNode(LRUNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(LRUNode *node)
    {
        node->next = m_head->next;
        node->prev = m_head;
        m_head->next = node;
        node->next->prev = node;
    }

    int removeLast()
    {
        LRUNode *last = m_tail->prev;
        int key = last->key;
        removeNode(last);
        delete last;
        return key;
    }

public:
    LRUCache(int capacity)
    {
        m_capacity = capacity;
        m_size = 0;

        m_head = new LRUNode();
        m_tail = new LRUNode();
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }

    int get(int key)
    {
        if (m_cache.find(key) == m_cache.end())
        {
            return -1;
        }

        LRUNode *target = m_cache.at(key);
        removeNode(target);
        addToHead(target);

        return target->val;
    }

    void put(int key, int value)
    {
        if (m_cache.find(key) == m_cache.end())
        {
            if (m_size == m_capacity)
            {
                int key_to_remove = removeLast();
                m_cache.erase(key_to_remove);
            }
            else
            {
                m_size++;
            }

            LRUNode *target = new LRUNode(key, value);
            addToHead(target);
            m_cache.emplace(key, target);
        }
        else
        {
            LRUNode *target = m_cache.at(key);
            target->val = value;

            removeNode(target);
            addToHead(target);
        }
    }
};
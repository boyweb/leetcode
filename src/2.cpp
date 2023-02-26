#include "leetcode_header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int next = 0;
		ListNode* p, * q;
		ListNode* r = NULL, * n = NULL;
		p = l1;
		q = l2;
		while (true) {
			int val = 0;
			if (p != NULL || q != NULL) {
				if (p != NULL) {
					val += p->val;
					p = p->next;
				}
				if (q != NULL) {
					val += q->val;
					q = q->next;
				}
				int r_val = (val + next) % 10;
				next = (val + next) / 10;

				if (n == NULL) {
					n = new ListNode(r_val);
					r = n;
				} else {
					n->next = new ListNode(r_val);
					n = n->next;
				}
			} else {
				break;
			}
		}

		if (next > 0) {
			if (n == NULL) {
				n = new ListNode(next);
				r = n;
			} else {
				n->next = new ListNode(next);
				n = n->next;
			}
		}

		return r;
	}
};
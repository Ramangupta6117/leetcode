/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getLength(ListNode *h) {
        int len = 0;
        for (; h; h = h->next) ++len;
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        int la = getLength(a), lb = getLength(b);
        if (la < lb) swap(a, b), swap(la, lb);
        for (int i = la - lb; i > 0; --i) a = a->next;
        while (a && b && a != b) a = a->next, b = b->next;
        return a;
    }
};
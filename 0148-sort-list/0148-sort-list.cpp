/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Merge two sorted lists
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(-1);  // Dummy node
        ListNode* temp = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left) temp->next = left;
        if (right) temp->next = right;

        return dummy.next;
    }

    // Recursive merge sort
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) return head;

        // Find middle of the list
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;  // Split the list into two half

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(mid);

        return merge(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
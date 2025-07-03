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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* st = head;
        ListNode* end = head;
        
        int i =0,j=0;
        ListNode* prev = NULL;
        while(end->next!=NULL){
            if(j-i+1==n){
                prev = st;
                st = st->next;
                i++;
            }
            end = end->next;
            j++;
        }
        if(prev==NULL){
            return head->next;
        }
        prev->next = st->next;
        return head;
    }
};
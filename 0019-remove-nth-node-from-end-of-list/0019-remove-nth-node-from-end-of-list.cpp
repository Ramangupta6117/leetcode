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
    void getsize(ListNode* head,int &size){
        if(head==nullptr){
            return;
        }
        ListNode* temp=head;
        while(temp->next!=nullptr){
            size++;
            temp=temp->next;
        }
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
       
        int size=1;
        getsize(head,size);
        int todelete=size-n+1;
        if(todelete==1){
            return head->next;
        }
        cout<<todelete<<" "<<size;
        ListNode * curr=head;
        ListNode* prev=nullptr;
        int pos=1;
        while(pos<todelete){
            prev=curr;
            curr=curr->next;
            pos++;
        }
        prev->next=curr->next;
        return head;
    }
};
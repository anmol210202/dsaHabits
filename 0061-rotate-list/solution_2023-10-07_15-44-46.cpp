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

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;
        if(head==NULL) return head;

        int size = 1; 

        while(curr->next!=NULL){
            curr=curr->next;
            size++;
        }

        k = size - k%size;
        if(k==0) return head;

        curr->next = head;
        while(k--) curr=curr->next;

        ListNode* newHead = curr->next;
        curr->next = NULL;
        
        return newHead;
    }
};

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lHead = new ListNode();
        ListNode* rHead = new ListNode();
        ListNode* lTail = lHead;
        ListNode* rTail = rHead;

        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = NULL;
            if(curr->val>=x){
                rTail->next = curr;
                rTail=rTail->next;
            } else {
                lTail->next = curr;
                lTail=lTail->next;
            }
            curr=next;
        }

        lTail->next = rHead->next;
        // ListNode* res = lHead->next;

        // delete lHead;

        return lHead->next;
        
    }
};

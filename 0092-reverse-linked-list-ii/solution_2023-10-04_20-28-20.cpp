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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* zeroNode = new ListNode();
        ListNode* prev = zeroNode;
        prev->next = head;
        
        int c=0;

        while(c<left-1){
            prev=prev->next;
            c++;
        }

        ListNode * curr = prev->next;
        c=0;
        while(c<right-left){
            ListNode* nxt = curr->next;
            // if(curr!=NULL and nxt!=NULL and prev!=NULL){
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
            // }
            c++;
        }
        
        return zeroNode->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return false;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL and slow!=NULL){
            fast = fast->next;
            if(fast!=NULL) fast = fast->next;

            slow= slow->next;

            if(slow==fast) return true;
        }

        return false;

    }
};

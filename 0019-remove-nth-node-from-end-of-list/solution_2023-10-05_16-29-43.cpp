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
        ListNode* zero = new ListNode();
        zero->next = head;

        ListNode* pre = zero;
        ListNode* curr = head;

        int size = 0;

        while(curr!=NULL){
            curr=curr->next;
            size++;
        }

        if(n>size) return NULL;

        if(size-n==0){
            head = head->next;
            return head;
        }

        int i=0;
        curr=head;

        while(i<size-n){
            pre = curr;
            curr = curr->next;
            i++;
        }

        pre->next = curr->next;
        curr->next = NULL;

        // cout<<pre->val<<" "<<curr->val<<endl;

        return zero->next;
    }
};

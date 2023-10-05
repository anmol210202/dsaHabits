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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* zero = new ListNode();
        zero->next = head;
        ListNode* curr = head;
        ListNode* pre = zero;
        unordered_map<int,bool> um;

        while(curr!=NULL){
            if(um.find(curr->val)!=um.end()) um[curr->val]=false;
            else um[curr->val]=true;
            curr=curr->next;
        }

        curr= head;

        while(curr!=NULL){
            if(!um[curr->val]){
                if(curr!=NULL ){
                    pre->next = curr->next;
                    curr=curr->next;
                } 
            } else {
                pre = curr;
                if(curr!=NULL) curr=curr->next;
            }
        }

        return zero->next;
    }
};

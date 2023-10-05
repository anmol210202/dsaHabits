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
        ListNode* zero = new ListNode();
        zero->next = head;
        ListNode* pre = zero;
        ListNode* curr = head;


        vector<int> v;

        while(curr!=NULL){
            if(curr->val>=x){
                v.push_back(curr->val);
                pre->next = curr->next;
                curr = curr->next;
            } else {
                pre = curr;
                curr=curr->next;
            }
        }
        
        for(auto &e:v){
            ListNode* tmp = new ListNode(e);
            pre->next = tmp;
            pre = pre->next;
        }

        return zero->next;
    }
};

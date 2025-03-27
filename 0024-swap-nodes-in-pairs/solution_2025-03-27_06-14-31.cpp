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
    ListNode* swapPairs(ListNode* head) {
        ListNode* zeroNode = new ListNode(0);
        zeroNode->next = head;

        ListNode* curr = zeroNode;
        while(curr->next && curr->next->next){
            ListNode *fir = curr->next;
            ListNode *sec = curr->next->next;
            
            fir->next = sec->next;
            sec->next = fir;
            curr->next = sec;
            curr = fir;
        }

        return zeroNode->next;
    }
};

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
        ListNode* zeroNode = new ListNode(0);
        zeroNode->next= head;

        int c = 0;

        ListNode* prev = zeroNode , *curr;
        while(c<left-1){
            prev = prev->next;
            c++;
        }
        curr = prev->next;
        for(int i=0; i<right-left; i++){
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return zeroNode->next;
    }
};

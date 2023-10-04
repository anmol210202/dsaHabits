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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res =new ListNode();
        ListNode* tail = res;

        while(list1!=NULL or list2!=NULL){
            if(list1==NULL){
                ListNode* temp = new ListNode(list2->val);
                tail->next = temp;
                tail=tail->next;
                list2= list2->next;
            } else if( list2==NULL){
                ListNode* temp = new ListNode(list1->val);
                tail->next = temp;
                tail=tail->next;
                list1=list1->next;
            } else if (list1->val > list2->val){
                ListNode* temp = new ListNode(list2->val);
                tail->next = temp;
                tail=tail->next;
                list2=list2->next;
            } else {
                ListNode* temp = new ListNode(list1->val);
                tail->next = temp;
                tail=tail->next;
                list1=list1->next;
            }
        }

        return res->next;
    }
};

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
    map<ListNode*,int> m ;
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        if(m.find(head)!=m.end()) return true;
        else m[head]++;
        return hasCycle(head->next);
    }
};

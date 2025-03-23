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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy; // Dummy head to simplify list operations.
        ListNode* curr = &dummy;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = carry; // Start with carry from the previous iteration.
            
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10; // Update carry.
            curr->next = new ListNode(sum % 10); // Create a new node with the current digit.
            curr = curr->next;
        }
        
        return dummy.next; // The result list starts from dummy.next.
    }
};


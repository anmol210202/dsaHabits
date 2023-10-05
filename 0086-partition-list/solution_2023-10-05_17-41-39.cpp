class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(); // Dummy node for the list with values less than x.
        ListNode* greaterHead = new ListNode(); // Dummy node for the list with values greater than or equal to x.
        ListNode* lessTail = lessHead;
        ListNode* greaterTail = greaterHead;
        
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }
            curr = curr->next;
        }

        // Connect the two lists.
        lessTail->next = greaterHead->next;
        greaterTail->next = nullptr;

        ListNode* newHead = lessHead->next; // The new head is the first node in the list with values less than x.

        delete lessHead; // Free the dummy nodes.

        return newHead;
    }
};


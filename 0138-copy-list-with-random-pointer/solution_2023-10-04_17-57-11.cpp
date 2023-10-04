/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        if(head == NULL) return NULL;

        while(curr!=NULL){
            Node* tmp = new Node(curr->val);
            tmp->next = curr->next;
            curr->next = tmp;
            curr = curr->next->next;
        }

        curr = head;

        while(curr!=NULL){
             if(curr->random) curr->next->random = curr->random->next;
             curr = curr->next->next;
        }

        curr = head;
        Node* res = head->next;
        Node* tmp = head->next;

        while(curr!=NULL){
            curr->next = tmp->next;
            curr= curr->next;
            if(tmp!=NULL and curr!=NULL )tmp->next = curr->next;
            tmp = tmp->next;
        }

        return res;

    }
};

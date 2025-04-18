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
        if(head ==NULL) return NULL;

        unordered_map<Node* , Node*> um;

        Node* curr = head;

        while(curr!=NULL){
            um[curr] = new Node(curr->val); 
            curr = curr->next;
        }

        curr = head;

        while(curr!=NULL){
            um[curr]->next = um[curr->next];
            um[curr]->random = um[curr->random];
            curr = curr->next;
        }

        return um[head];
    }
};

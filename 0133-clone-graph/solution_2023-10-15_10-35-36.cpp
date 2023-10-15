/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> um;
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        vector<Node*> neighbor;

        Node* tmp = new Node(node->val);
        um[node]=tmp;

        for(auto e:node->neighbors){
            if(um.find(e)!=um.end()){
                neighbor.push_back(um[e]);
            } else {
                Node* tmp1 = cloneGraph(e);
                neighbor.push_back(tmp1);
            }
        }
        tmp->neighbors = neighbor;

        return tmp;
    }
};

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
    
    Node* dfs(Node* root , map<Node*,Node*> &m){
        vector<Node*> neighbor ; 
        Node* tmp = new Node(root->val);
        m[root]=tmp;
        for(auto e:root->neighbors){
            if(m.find(e)!=m.end()){
                neighbor.push_back(m[e]);
            } else {
                neighbor.push_back(dfs(e,m));
            }
        }
        tmp->neighbors = neighbor;
        return tmp; 
    }

    Node* cloneGraph(Node* node) {
        map<Node* , Node*> m;
        if(node == NULL) return NULL;
        // if(node->neighbors.size()==0){
        //     Node* tmp = new Node(node->val);
        //     return tmp;
        // }
        return dfs(node , m);
    }
};

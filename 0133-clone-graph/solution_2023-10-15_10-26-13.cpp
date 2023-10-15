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
    
    Node* dfs(Node* root , unordered_map<Node* , Node*> &um){
        Node* tmp = new Node(root->val);
        vector<Node*> neighbor;
        um[root]=tmp;

        for(auto e:root->neighbors){
            if(um.find(e)!=um.end()){
                neighbor.push_back(um[e]);
            } else {
                neighbor.push_back(dfs(e,um));
            }
        }
        tmp->neighbors = neighbor;
        return tmp;
        
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(node->neighbors.empty()) {
            Node* tmp = new Node(node->val);
            return tmp;
        }
        unordered_map<Node*, Node*> um;
        return dfs(node , um);

    }
};

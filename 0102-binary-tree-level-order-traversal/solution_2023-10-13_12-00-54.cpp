/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        vector<int> v;
        queue<TreeNode*> q;

        if(!root) return vv;
        q.push(root);
        q.push(NULL); /// detection of levels

        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();

            if(curr==NULL){
                // level crosed
                vv.push_back(v);
                v.clear();
                if(!q.empty()) q.push(NULL);
            } else {
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right); 
            }
        }
        return vv;
    }
};

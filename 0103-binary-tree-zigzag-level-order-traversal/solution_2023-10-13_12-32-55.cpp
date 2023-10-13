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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> v;
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        int h=0;

        if(!root) return vv;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr==NULL){
                // next level;
                h++;
                if(h%2==0) reverse(v.begin(),v.end());
                vv.push_back(v);
                v.clear();
                if(!q.empty()) q.push(NULL);
                // x=1;
            } else {
                v.push_back(curr->val);
                // if(h%2!=1){
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                // }else {
                    // if(curr->right) q.push(curr->right);
                    // if(curr->left) q.push(curr->left);
                // }
            }
        }

        return vv;
    }
};

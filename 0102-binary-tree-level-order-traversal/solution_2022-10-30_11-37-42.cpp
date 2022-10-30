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
    int hFind(TreeNode* root){
        if(!root) return 0;
        int l=hFind(root->left);
        int r=hFind(root->right);
        return 1+(l>r ?l:r);
    }
    
    void fVector(TreeNode* root ,vector<vector<int>> &v , int h ,int curr=0){
        if(!root || curr>h) return ;
        v[curr].push_back(root->val);
        fVector(root->left,v,h,curr+1);
        fVector(root->right,v,h,curr+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        int height = hFind(root);
        vector<vector<int>> v(height);
        fVector(root,v,height-1);
        return v;
    }
};

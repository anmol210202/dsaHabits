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
    // int ans = 0;

    void traverse(TreeNode* root , int num , int &ans){
        if(!root->left and !root->right){
            ans+=num*10+root->val;
            return ;
        }

        if(root->left){
            traverse(root->left , num*10 + root->val ,ans);
        }
        if(root->right){
            traverse(root->right , num*10 + root->val , ans);
        }
        return ;
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        traverse(root,0,ans);
        return ans;
    }
};

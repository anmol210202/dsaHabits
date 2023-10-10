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

    bool traverse(TreeNode* root,int targetSum){
        if(!root->left and !root->right){
            if(targetSum - root->val == 0) return true;
            return false;
        }
        if(root->left){
            if(traverse(root->left,targetSum-root->val)) return true;
        }
        if(root->right){
            if(traverse(root->right,targetSum-root->val)) return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return traverse(root,targetSum);
    }
};

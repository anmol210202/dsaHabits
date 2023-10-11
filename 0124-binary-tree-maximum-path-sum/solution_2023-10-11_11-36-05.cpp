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
     
    int traverse(TreeNode* root , int &maxSum){
        if(!root) return 0;
        if(!root->left and !root->right){
            maxSum = max(maxSum,root->val);
            return root->val;
        }

        int leftSum = traverse(root->left , maxSum);
        int rightSum = traverse(root->right , maxSum);
        maxSum = max(maxSum , max(root->val , max(leftSum , max(rightSum , leftSum + rightSum))+root->val));
        return max(root->val , max(rightSum , leftSum)+root->val);
    }
     
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        if(!root) return root->val;
        traverse(root,maxSum);
        return maxSum;
    }
};

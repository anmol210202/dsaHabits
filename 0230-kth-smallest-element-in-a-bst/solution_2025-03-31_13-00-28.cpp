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
private:
    void inorder(TreeNode* node,int &ans, int &k){
        if(!node) return ;
        if(node->left) inorder(node->left,ans,k);
        k--;
        if(k==0){
        ans = node->val;
            return ;
        }
        if(node->right) inorder(node->right,ans,k);
        }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorder(root,ans,k);
        return ans;
    }
};

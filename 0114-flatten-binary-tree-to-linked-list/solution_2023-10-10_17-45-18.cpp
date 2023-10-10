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
    void flatten(TreeNode* root) {
        if(!root or !root->left and !root->right) return ;

        if(root->left){
            flatten(root->left);

            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = NULL;

            TreeNode* tmp1 = root->right;
            while(tmp1->right) tmp1 = tmp1->right;
            tmp1->right = tmp;
        }
        flatten(root->right);
    }
};

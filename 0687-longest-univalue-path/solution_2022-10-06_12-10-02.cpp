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
    int x=0;
    int mk(TreeNode* root,int &a) {
        if(root==NULL) return 0;
        int l=root->left?mk(root->left,a):0;
        int r=root->right?mk(root->right,a):0;
        l=(root->left and root->left->val==root->val)?l+1:0;
        r=(root->right and root->right->val==root->val)?r+1:0;
            // cout<<l<<" "<<r<<endl;;
        a=max(a,l+r);
        
        return max(l,r);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        mk(root,ans);
        return ans;
    }
};

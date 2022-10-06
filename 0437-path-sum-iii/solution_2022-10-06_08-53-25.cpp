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
    int mk(TreeNode* root , int targetSum , vector<int> v) {
        if(root==NULL) return 0;
        v.push_back(root->val);
        long long sum=0;
        for(int i=v.size()-1; i>=0; i--){
            sum+=v[i];
            if(sum==targetSum)  x++;
            // cout<<v[i]<<" ";
        }
        // cout<<endl;
        
        mk(root->left,targetSum,v);
        mk(root->right,targetSum,v);
        return x;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        return mk(root,targetSum,v);
    }
};

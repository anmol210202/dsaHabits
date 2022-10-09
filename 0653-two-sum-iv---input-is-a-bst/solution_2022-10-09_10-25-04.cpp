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
    vector<int> v;
    
    bool isPairSum(vector<int> &A, int X)
{
        int N =A.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            if (A[i] + A[j] == X)
                return true;
            if (A[i] + A[j] > X)
                break;
        }
    }
    return false;
}
    
    void mk(TreeNode* root ){
        if(root==NULL) return;
        
        v.push_back(root->val);
        
        mk(root->left);
        mk(root->right);
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        mk(root);
        // for(auto e:v){
        //     cout<<e<<" ";
        // }
        sort(v.begin(),v.end());
        return isPairSum(v,k);
    }
};

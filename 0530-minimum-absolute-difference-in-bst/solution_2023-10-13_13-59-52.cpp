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
    // int minOfThree(int a, int b, int c) {
    //     return std::min(a, std::min(b, c));
    // }

    void traverse(TreeNode* root , int &minVal , int &prev){
        if(!root) return ;

        traverse(root->left , minVal,prev);
        if(prev!=-1){
            minVal = min(minVal , root->val - prev);
        }
        prev = root->val;
        traverse(root->right , minVal,prev);
    }

    int getMinimumDifference(TreeNode* root) {
        int minVal = INT_MAX,prev = -1;
        traverse(root, minVal , prev);
        return minVal;
    }
};

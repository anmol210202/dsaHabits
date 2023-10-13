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
    void traverse(TreeNode* root , vector<double> &v){
        if(!root) return ;
        double sum = 0 , count=0; 
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr==NULL){
                // next level
                v.push_back(sum/count);
                sum = 0;
                count = 0;
                if(!q.empty()) {
                    q.push(NULL);
                }
            } else {
                sum+=curr->val;
                count++;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        traverse(root,v);
        return v;
    }
};

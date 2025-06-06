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
    void traverse(TreeNode* root , vector<int> &v , unordered_set<int> &us , int h){
        if(!root) return ;
        if(us.find(h)==us.end()){
            v.push_back(root->val);
            us.insert(h);
        }

        // TreeNode *l ,*r;

        traverse(root->right,v,us,h+1);
        traverse(root->left,v,us,h+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        unordered_set<int> us;
        traverse(root,v,us,1);
        return v;
    }
};

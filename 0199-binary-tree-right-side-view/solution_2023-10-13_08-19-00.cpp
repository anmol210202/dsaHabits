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
    void traverse(TreeNode* root, vector<int> &v, map<int,bool> &m , int height){
        if(!root) return ;
        if(m.find(height)==m.end()){
            m[height]=true;
            v.push_back(root->val);
        }
        traverse(root->right , v , m , height+1);
        traverse(root->left , v , m , height+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        map<int,bool> m;
        traverse(root,v,m , 1);
        return v;
    }
};

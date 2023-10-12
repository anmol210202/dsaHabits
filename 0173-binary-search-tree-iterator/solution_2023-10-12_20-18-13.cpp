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
class BSTIterator {
public:

    stack<TreeNode* > s;

    BSTIterator(TreeNode* root) {
        stackPush(root);
    }
    
    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        stackPush(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }

    void stackPush(TreeNode* tmp){
        while(tmp){
            s.push(tmp);
            tmp = tmp->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

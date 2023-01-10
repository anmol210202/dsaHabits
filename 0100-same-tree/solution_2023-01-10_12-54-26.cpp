class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q and !p) return true;
        if((!p||!q)||q->val!=p->val) return false;
        return isSameTree(p->left,q->left) and   isSameTree(p->right,q->right);
    }
};

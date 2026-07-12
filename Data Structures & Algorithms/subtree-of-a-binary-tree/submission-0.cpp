class Solution {
public:
    bool isSameTree(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if (!l || !r) return false;  // fixed here
        return (l->val == r->val) &&
               isSameTree(l->left, r->left) &&
               isSameTree(l->right, r->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) ||   // fixed return
               isSubtree(root->right, subRoot);    // fixed return
    }
};


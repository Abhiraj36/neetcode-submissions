class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) return nullptr;

        int rootVal = preorder[idx];
        TreeNode* root = new TreeNode(rootVal);
        idx++; // move to next node in preorder

        // Find root in inorder
        int i = start;
        for (; i <= end; i++) {
            if (inorder[i] == rootVal) break;
        }

        // Build left and right subtrees
        root->left = solve(preorder, inorder, start, i-1, idx);
        root->right = solve(preorder, inorder, i+1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return solve(preorder, inorder, 0, preorder.size()-1, idx);
    }
};


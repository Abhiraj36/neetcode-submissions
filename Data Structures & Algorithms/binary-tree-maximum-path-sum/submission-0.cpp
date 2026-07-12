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
    int maxSum;

    int solve(TreeNode* root){
        if(root == NULL) {
            return 0;
        }

        int l = solve(root->left);
        int r = solve(root->right);

        // NEGATIVE VALUES SHOULD NOT BE CARRIED UPWARD
        l = max(0, l);
        r = max(0, r);

        int neeche_hi_milgya_answer = l + r + root->val;
        int koi_ek_acha = max(l, r) + root->val;
        int only_root_acha = root->val;

        maxSum = max({maxSum, neeche_hi_milgya_answer, koi_ek_acha, only_root_acha});

        return max(koi_ek_acha, only_root_acha);
    }

    int maxPathSum(TreeNode* root) {

        maxSum = INT_MIN;   // colon hata diya
        solve(root);
        return maxSum;      // typo fix: maxSUm -> maxSum
    }
};

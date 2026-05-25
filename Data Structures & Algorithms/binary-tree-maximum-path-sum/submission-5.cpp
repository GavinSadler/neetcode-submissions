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
    int globalMax = INT_MIN;

    int getMax(TreeNode* n) {
        if (n == nullptr) return 0;
        
        int lm = getMax(n->left);
        int rm = getMax(n->right);
        int nv = n->val;

        int m = max(
            nv,
            max(
                nv + lm,
                nv + rm
            )
        );

        globalMax = max(
            max(
                m,
                nv + lm + rm
            ),
            globalMax
        );

        return m;
    }

public:
    int maxPathSum(TreeNode* root) {
        getMax(root);
        return globalMax;
    }
};

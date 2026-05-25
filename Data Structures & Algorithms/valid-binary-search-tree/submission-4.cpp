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
    bool isValidBST(TreeNode* root) {
        return checkNode(root, INT_MIN, INT_MAX);
    }

    bool checkNode(TreeNode* n, int leftBound, int rightBound) {
        if (!n) return true;

        if (!(leftBound < n->val && n->val < rightBound) ) return false;

        return checkNode(n->left, leftBound, n->val) && checkNode(n->right, n->val, rightBound);
    }
};

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
        queue<tuple<TreeNode*, int, int>> q;

        q.push(make_tuple(root, INT_MIN, INT_MAX));

        while(!q.empty()) {
            auto [n, left, right] = q.front();
            q.pop();

            if (!(left < n->val && n->val < right)) {
                return false;
            }

            if (n->left)
                q.push(make_tuple(n->left, left, n->val));
            
            if (n->right)
                q.push(make_tuple(n->right, n->val, right));
        }

        return true;
    }

    // bool checkNode(TreeNode* n, int leftBound, int rightBound) {
    //     if (!n) return true;

    //     if (!(leftBound < n->val && n->val < rightBound) ) return false;

    //     return checkNode(n->left, leftBound, n->val) && checkNode(n->right, n->val, rightBound);
    // }
};

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
    TreeNode* getLCA(TreeNode* r, TreeNode* p, TreeNode* q) {
        int rv = r->val;
        int pv = p->val;
        int qv = q->val;

        if (r == p) {
            return p;
        } else if (r == q) {
            return q;
        } else if (pv < rv && qv > rv || pv > rv && qv < rv ) {
            return r;
        } else if (pv < rv && qv < rv) {
            return getLCA(r->left, p, q);
        } else if (pv > rv && qv > rv) {
            return getLCA(r->right, p, q);
        }

        return nullptr;
    } 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return getLCA(root, p, q);
    }
};

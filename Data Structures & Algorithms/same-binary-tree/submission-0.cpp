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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qp;
        queue<TreeNode*> qq;

        qq.push(q);
        qp.push(p);

        while(!qq.empty()) {
            TreeNode* pn = qp.front();
            qp.pop();

            TreeNode* qn = qq.front();
            qq.pop();

            // Null mismatch
            if ((pn == nullptr || qn == nullptr) && qn != pn) {
                return false;
            }

            // Value mismatch
            if ((pn != nullptr && qn != nullptr) && pn->val != qn->val) {
                return false;
            }

            if (qn != nullptr){
                qq.push(qn->left);
                qq.push(qn->right);
            }
            
            if (pn != nullptr){
                qp.push(pn->left);
                qp.push(pn->right);
            }
        }

        return true;
    }
};

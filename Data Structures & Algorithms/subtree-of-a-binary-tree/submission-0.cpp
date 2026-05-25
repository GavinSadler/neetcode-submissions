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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();

            if (!t) {
                continue;
            }

            if (t->val == subRoot->val) {
                // Do a check on the subtree here...
                queue<pair<TreeNode*, TreeNode*>> qPrime;

                bool validSubtree = true;

                qPrime.push({t, subRoot});

                while(!qPrime.empty() && validSubtree) {
                    auto [a, b] = qPrime.front();
                    qPrime.pop();

                    if (!a && !b) {
                        continue;
                    }

                    if (!a || !b || a->val != b->val){
                        validSubtree = false;
                        break;
                    }

                    qPrime.push({a->left, b->left});
                    qPrime.push({a->right, b->right});
                }

                if (validSubtree) {
                    return true;
                }
            }

            q.push(t->left);
            q.push(t->right);
        }

        return false;
    }
};

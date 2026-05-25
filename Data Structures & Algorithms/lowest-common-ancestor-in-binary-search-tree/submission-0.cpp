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
    vector<TreeNode*> findAncestors(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> ancestors;

        stack<pair<TreeNode*, vector<TreeNode*>>> s;

        s.push({root, {}});

        while(!s.empty()) {
            auto [n, a] = s.top();
            s.pop();
            a.push_back(n);

            if (n == p) {
                return a;
            }

            if (n->left)
                s.push({n->left, a});

            if (n->right)
                s.push({n->right, a});
        }

        return {};
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pa = findAncestors(root, p);
        vector<TreeNode*> qa = findAncestors(root, q);

        TreeNode* lca = nullptr;

        for(int i = 0; i < min(pa.size(), qa.size()); i++) {
            if (pa[i] == qa[i]) {
                lca = pa[i];
            } else {
                break;
            }
        }

        return lca;
    }
};

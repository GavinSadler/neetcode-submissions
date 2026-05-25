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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (!root) return {};
        
        vector<vector<int>> out;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> layer;

            int qs = q.size();

            for(int i = 0; i < qs; i++) {
                TreeNode* n = q.front();
                q.pop();

                layer.push_back(n->val);

                if (n->left)
                    q.push(n->left);

                if (n->right)
                    q.push(n->right);
            }

            out.push_back(layer);
        }

        return out;
    }
};

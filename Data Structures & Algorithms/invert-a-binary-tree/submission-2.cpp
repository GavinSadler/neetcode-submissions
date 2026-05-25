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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        queue<TreeNode*> queue;

        queue.push(root);

        while(!queue.empty()) {
            TreeNode* n = queue.front();
            
            queue.pop();
            
            swap(n->left, n->right);

            if (n->left)
                queue.push(n->left);
                
            if (n->right)
                queue.push(n->right);
        }

        return root;
    }
};

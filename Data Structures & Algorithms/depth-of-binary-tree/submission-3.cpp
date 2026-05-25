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
    int maxDepth(TreeNode* root) {
        int depth = 0;

        queue<TreeNode*> q;

        if (root != nullptr)
            q.push(root);

        while(!q.empty()) {

            depth++;
            int currentSize = q.size();

            for(int i = 0; i < currentSize; i++) {

                // Empty the queue between each iteration
                TreeNode* qt = q.front();
                q.pop();

                if (qt->left)
                    q.push(qt->left);
            
                if (qt->right)
                    q.push(qt->right);
            }

        }

        return depth;
    }
};

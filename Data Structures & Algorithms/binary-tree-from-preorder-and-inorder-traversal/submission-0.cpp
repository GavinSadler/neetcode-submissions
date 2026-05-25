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

    TreeNode* construct(
        vector<int>::iterator poBegin,
        vector<int>::iterator poEnd,
        vector<int>::iterator ioBegin,
        vector<int>::iterator ioEnd
    ) {
        if (poBegin == poEnd) return nullptr;

        int rn = *poBegin;

        TreeNode* out = new TreeNode(rn);
        
        auto ioi = find(ioBegin, ioEnd, rn);
        int leftSize = ioi - ioBegin;

        out->left = construct(
            poBegin + 1,
            poBegin + 1 + leftSize,
            ioBegin,
            ioi
        );

        out->right = construct(
            poBegin + 1 + leftSize,
            poEnd,
            ioi + 1,
            ioEnd
        );

        return out;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(
            preorder.begin(),
            preorder.end(),
            inorder.begin(),
            inorder.end()
        );
    }
};

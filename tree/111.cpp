/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int heightOfLeft = minDepth(root->left);
        int heightOfRight = minDepth(root->right);
        if (heightOfRight == 0)
            return heightOfLeft + 1;
        if (heightOfLeft == 0)
            return heightOfRight + 1;
        return heightOfLeft > heightOfRight ? heightOfRight + 1 : heightOfLeft + 1;
    }

        
};
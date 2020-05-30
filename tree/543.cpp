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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return res;
        h(root);
        return res;
    }

    int h(TreeNode* n)
    {
        if (n == NULL)
            return 0;
        int left = h(n->left);
        int right = h(n->right);
        res = max(left + right, res);
        return max(left, right) + 1;
    }
};
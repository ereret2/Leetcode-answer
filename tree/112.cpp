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
    bool hasPathSum(TreeNode* root, int sum) {
        int tmp = 0;
        if (root == NULL)
            return false;
        return hasPathSum(root, sum, tmp);
    }

    bool hasPathSum(TreeNode* root, int sum, int& tmp)
    {
        tmp += root->val;
        //cout << tmp << endl;
        if (tmp == sum && root->left == NULL && root->right == NULL)
            return true;
        bool left = false, right = false;
        if (root->left)
            left = hasPathSum(root->left, sum, tmp);
        if (root->right)
            right = hasPathSum(root->right, sum, tmp);
        tmp -= root->val;
        return left | right;
    }
};
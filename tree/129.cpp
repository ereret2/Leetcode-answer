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
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        int tmp = 0;
        if (root == NULL)
            return sum;
        hasPathSum(root, tmp);
        return sum;
    }

    void hasPathSum(TreeNode* root, int& tmp)
    {
        tmp *= 10;
        tmp += root->val;
        if (root->left == NULL && root->right == NULL)
        {
            
            sum += tmp;
        }
        if (root->left)
            hasPathSum(root->left, tmp);
        if (root->right)
            hasPathSum(root->right, tmp);
        tmp -= root->val;
        tmp /= 10;
    }
};
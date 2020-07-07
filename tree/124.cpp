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
    int globalMaximum;
    int maxPathSum(TreeNode* root) {
        globalMaximum = INT_MIN;
        findGlobalMaximum(root);
        return globalMaximum;
    }

    int findGlobalMaximum(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int maximumPathLengthLeft = max(findGlobalMaximum(root->left), 0);
        int maximumPathLengthRight = max(findGlobalMaximum(root->right), 0);

        globalMaximum = max(maximumPathLengthLeft + maximumPathLengthRight + root->val, globalMaximum);

        return maximumPathLengthLeft > maximumPathLengthRight ? maximumPathLengthLeft + root->val : maximumPathLengthRight + root->val;
        
    }
};
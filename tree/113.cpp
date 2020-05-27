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
    vector<vector<int>> paths;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int tmp = 0;
        if (root == NULL)
            return paths;
        vector<int> path;
        hasPathSum(root, sum, tmp, path);
        return paths;
    }

    void hasPathSum(TreeNode* root, int sum, int& tmp, vector<int>& path)
    {
        path.push_back(root->val);
        tmp += root->val;
        if (tmp == sum && root->left == NULL && root->right == NULL)
        {
            paths.push_back(path);
        }
        if (root->left)
            hasPathSum(root->left, sum, tmp, path);
        if (root->right)
            hasPathSum(root->right, sum, tmp, path);
        tmp -= root->val;
        path.pop_back();
    }
};
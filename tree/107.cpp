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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int levelSize = queue.size();
            vector<int> currLevel;
            for (int j = 0; j < levelSize; j++)
            {
                TreeNode* tmp = queue.front();
                queue.pop();
                currLevel.push_back(tmp->val);
                
                if (tmp->left)
                    queue.push(tmp->left);
                if (tmp->right)
                    queue.push(tmp->right);
            }
            res.insert(res.begin(), currLevel);
        }
        return res;
    }
};
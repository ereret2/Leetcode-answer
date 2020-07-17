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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == NULL)
            return res;
        
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            int levelSize = queue.size();
            double sum = 0;
            for (int j = 0; j < levelSize; j++)
            {
                TreeNode* tmp = queue.front();
                queue.pop();
                sum += tmp->val;
                
                if (tmp->left)
                    queue.push(tmp->left);
                if (tmp->right)
                    queue.push(tmp->right);
            }
            res.push_back(sum / levelSize);
        }
        return res;
    }
};
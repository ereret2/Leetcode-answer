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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* t = s.top();
            s.pop();
            int tmp = 0;
            bfs(tmp, t, sum);
            if (t->left != NULL)
                s.push(t->left);
            if (t->right != NULL)
                s.push(t->right);
        }
        
        return res;
    }

    void bfs(int& tmp, TreeNode* node, int sum)
    {
        int t = tmp;
        tmp += node->val;
        //printf("%d\n", tmp);
        if (tmp == sum)
            res += 1;
        if (node->left != NULL)
            bfs(tmp, node->left, sum);
        if (node->right != NULL)
            bfs(tmp, node->right, sum);
        tmp = t;
    }
};
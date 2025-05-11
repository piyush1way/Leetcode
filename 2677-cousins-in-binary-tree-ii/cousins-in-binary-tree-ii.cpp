/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // calculate the sum at each level
        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelsum;
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            levelsum.push_back(sum);
        }
        // fill the node values
        root->val = 0;
        q.push(root);
        int level =1;
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                sum=0;
                if (node->left) {
                    sum+=node->left->val;
                }
                if (node->right) {
                    sum+=node->right->val;
                }
                if (node->left) {
                    node->left->val = levelsum[level]- sum;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = levelsum[level]- sum;
                    q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};
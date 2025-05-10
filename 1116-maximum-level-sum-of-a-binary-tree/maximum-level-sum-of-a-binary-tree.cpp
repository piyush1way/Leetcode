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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int maxi = INT_MIN;
        int sum = 0;
        int level=1;
        int ans;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            sum=0;
            while (n--) {
                TreeNode* node = q.front();
                sum+=node->val;
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if(sum>maxi){
                maxi = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }

}
;
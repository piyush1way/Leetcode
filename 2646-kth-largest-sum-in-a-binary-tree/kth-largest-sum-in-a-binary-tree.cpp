/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include <functional>  // for greater<>
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<pair<long long ,long long >>ans; // sum,level
        long long maxi = INT_MIN;
        long long sum = 0;
        int level=1;
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
            ans.push_back({sum,level});
        }
        sort(ans.begin(),ans.end());
        if(k>ans.size()){
            return -1;
        }
        int n = ans.size();
        return ans[n-k].first;
    }
};
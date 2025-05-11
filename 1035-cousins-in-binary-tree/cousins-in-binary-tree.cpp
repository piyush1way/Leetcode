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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag1 = false;
        bool flag2 = false;
        while (!q.empty()) {
            int n = q.size();
            flag1 = false;
            flag2 = false;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && node->right){
                    if (((node->left->val == x) && (node->right->val == y)) ||
                        ((node->right->val == x) && (node->left->val == y))){
return false;
                    }
                    
                }
                if(node->val==x){
                    flag1 = true;
                }
                else if(node->val==y){
                    flag2 = true;
                }
                if(node->left){
                    q.push(node->left);
    
                }
                if(node->right){
                    q.push(node->right);
                    
                }
            }
            if (flag1 && flag2) {
                return true;
            }
        }
        return false;
    }
};
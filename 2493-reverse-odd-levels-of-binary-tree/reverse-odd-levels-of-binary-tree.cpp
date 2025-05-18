class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodesAtLevel;

            // Collect nodes at this level
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (level % 2 == 1) {
                    nodesAtLevel.push_back(curr);
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Reverse values at odd level
            if (level % 2 == 1) {
                int i = 0, j = nodesAtLevel.size() - 1;
                while (i < j) {
                    swap(nodesAtLevel[i]->val, nodesAtLevel[j]->val);
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};

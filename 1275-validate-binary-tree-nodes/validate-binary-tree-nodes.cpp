class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);

        // Count how many times each node is pointed to
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (++indegree[leftChild[i]] > 1)
                    return false; // A node has more than one parent
            }
            if (rightChild[i] != -1) {
                if (++indegree[rightChild[i]] > 1)
                    return false;
            }
        }

        // Find the root (only one node should have indegree 0)
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (root != -1)
                    return false; // More than one root
                root = i;
            }
        }

        if (root == -1) return false; // No root found

        // BFS/DFS to check full connectivity and no cycles
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            int left = leftChild[curr];
            int right = rightChild[curr];

            if (left != -1) {
                if (visited[left]) return false;
                visited[left] = true;
                q.push(left);
            }

            if (right != -1) {
                if (visited[right]) return false;
                visited[right] = true;
                q.push(right);
            }
        }

        // All nodes must be visited (connected)
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};

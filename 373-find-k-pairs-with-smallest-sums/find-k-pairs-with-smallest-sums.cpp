class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int N = A.size();
        int M = B.size(); 
        // Max heap to store (sum, indexA, indexB)
        // priority_queue<pair<int, pair<int, int>>> pq;
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        set<pair<int, int>> visited;
        pq.push({A[0] + B[0], {0, 0}});
        visited.insert({0, 0});

        vector<vector<int>> ans;
        while (k-- && !pq.empty()) {
            auto temp = pq.top();
            int sum = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            ans.push_back({A[i], B[j]});
            pq.pop();

            if (i + 1 < N && visited.find({i + 1, j}) == visited.end()) {
                pq.push({A[i + 1] + B[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            if (j + 1 < M && visited.find({i, j + 1}) == visited.end()) {
                pq.push({A[i] + B[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                       greater<pair<int, vector<int>>>>
            q;
        // dist ,vector

        for (auto p : points) {
            int x = p[0];
            int y = p[1];
            vector<int> temp;
            temp.push_back(x);
            temp.push_back(y);
            int dist = (x*x + y*y);
            q.push({abs(dist), {temp}});
        }
        vector<vector<int>> ans;
        while (k--) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
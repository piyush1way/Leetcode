class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        // min-heap: pair<dropOffLocation, numPassengers>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int currentPassengers = 0;

        for (const auto& trip : trips) {
            int num = trip[0];
            int from = trip[1];
            int to = trip[2];

            while (!pq.empty() && pq.top().first <= from) {
                currentPassengers -= pq.top().second;
                pq.pop();
            }
            currentPassengers += num;
            if (currentPassengers > capacity) return false;

            pq.push({to, num});
        }

        return true;
    }
};
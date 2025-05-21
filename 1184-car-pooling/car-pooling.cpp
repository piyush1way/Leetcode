class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        for (int i = 0; i < n; i++) {
            int currPassengers = trips[i][0];
            int end = trips[i][2];

            for (int j = 0; j < i; j++) {
                // If a previous trip's drop-off is after current trip's start,
                // the passengers are still in the car
                if (trips[j][2] > trips[i][1]) {
                    currPassengers += trips[j][0];
                }
            }

            if (currPassengers > capacity)
                return false;
        }

        return true;
    }
};
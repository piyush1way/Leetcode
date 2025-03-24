class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        if (n == 0)
            return days;

        sort(meetings.begin(), meetings.end()); 

        int cnt = 0;
        cnt += meetings[0][0] - 1; 
        int end = meetings[0][1]; 

        for (int i = 1; i < n; i++) {
            if (meetings[i][0] > end) { 
                cnt += meetings[i][0] - end - 1;
            }
            end = max(
                end,
                meetings[i][1]); 
        }

        cnt += (days - end); 
        return cnt;
    }
};
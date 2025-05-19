class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>q;
        long long sum = 0;
        for(int i =0;i<gifts.size();i++){
            q.push(gifts[i]);
            sum+=gifts[i];
        }
        while(k--){
            int curr = q.top();
            q.pop();
            int neww = sqrt(curr);
            sum = sum - (curr-neww);
            q.push(neww);
        }
        return sum;
    }
};
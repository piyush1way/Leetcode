class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        int sum = 0;
        for(int i =0;i<piles.size();i++){
            q.push(piles[i]);
            sum+=piles[i];
        }
        while(k--){
            int curr = q.top();
            q.pop();
            int neww = ceil(curr / 2.0);
            sum = sum - (curr-neww);
            q.push(neww);
        }
        return sum;
    }
};
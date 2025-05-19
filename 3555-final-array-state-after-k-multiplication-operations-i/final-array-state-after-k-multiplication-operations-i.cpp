class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // node, position  pair<int,int>
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push({nums[i],i});
        }
        while(k--){
            pair<int,int>temp = q.top();
            q.pop();
            int x = temp.first;
            int pos = temp.second;
            int y = x * multiplier;
            q.push({y,pos});
        }
        vector<int> ans(n);
        while(!q.empty()){
            int num = q.top().first;
            int pos = q.top().second;
            q.pop();
            ans[pos]=num;
        }
        return ans;
    }
};
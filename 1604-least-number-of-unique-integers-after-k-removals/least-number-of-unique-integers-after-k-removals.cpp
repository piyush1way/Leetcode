class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mpp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i =0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(auto it: mpp){
            q.push({it.second,it.first});
        }
        while(k){
            int freq = q.top().first;
            int node = q.top().second;
            if(k>=freq){
                q.pop();
                k=k-freq;
            }
            else{
                break;
            }
        }
        return q.size();
    }
};
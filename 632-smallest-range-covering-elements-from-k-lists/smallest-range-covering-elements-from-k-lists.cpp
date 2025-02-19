#include <iostream>
#include <algorithm>
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int minimum = INT_MAX;
        int maximum = INT_MIN;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        for (int i = 0; i < n; i++) {
            q.push({nums[i][0],{i,0}});
            maximum = max(maximum, nums[i][0]);
        }
        minimum=q.top().first;
        vector<int>ans(2);
        ans[0]=minimum;
        ans[1]=maximum;
        int ele,row,col;
        pair<int,pair<int,int>>temp;
        while(q.size()==nums.size()){
            temp=q.top();
            q.pop();
            ele=temp.first;
            row=temp.second.first;
            col=temp.second.second;

            if(col+1<nums[row].size()){
                q.push({nums[row][col+1],{row,col+1}});
                maximum=max(maximum,nums[row][col+1]);
                minimum=q.top().first;
            }
            //if got smaller range
            if(maximum-minimum <ans[1]-ans[0]){
                ans[0]=minimum;
                ans[1]=maximum;
            }
        }
        return ans;

    }
};
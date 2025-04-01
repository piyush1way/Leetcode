class Solution {
public:

    long long f(int pos,vector<vector<int>>& questions,vector<long long>&dp){
        if(pos>=questions.size()){
            return 0;
        }
        if(dp[pos]!=-1){
            return dp[pos];
        }
        long long exclude = f(pos+1,questions,dp);
        long long include = questions[pos][0]+f(questions[pos][1]+pos+1,questions,dp);
        return dp[pos]=max(include,exclude);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,-1);
        return f(0,questions,dp);
    }

};
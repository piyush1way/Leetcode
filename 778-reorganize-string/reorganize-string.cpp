class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int,char>>q;  // pair<int,char> freq, char
        int freq[26]={0};
        int maxi = 0;
        for(int i =0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i =0;i<26;i++){
            if(freq[i]){
                q.push({freq[i],i+'a'});
            }
            maxi = max(maxi,freq[i]);
        }
        if(maxi > (n+1)/2){
            return "";
        }
        string ans ="";
        pair<int,char> prev = {0,'#'};
        while(ans.size()!=n){
            pair<int,char> curr = q.top();
            q.pop();
            char ch = curr.second;
            curr.first--;
            
            ans.push_back(ch);
            if(prev.first>0){
                q.push(prev);
            }
            prev = curr;
        }
        return ans;

    }
};
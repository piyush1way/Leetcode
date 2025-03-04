class Solution {
public:
    bool checkPowersOfThree(int n) {
        string temp="";
        while(n){
            int rem = n%3;
            n=n/3;
            temp+= ('0'+rem);
        }
        for(int i =0;i<temp.size();i++){
            if(temp[i]=='0' || temp[i]=='1'){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        set<pair<int, int>> st;
        st.insert({0,0});
        int n = path.size();
        for(int i =0;i<n;i++){
            if(path[i]=='S'){
                y--;
            }
            else if(path[i]=='E'){
                x++;
            }
            else if(path[i]=='W'){
                x--;
            }
            else if(path[i]=='N'){
                y++;
            }
            if(st.count({x,y})){
                return true;
            }
            
                st.insert({x,y});
            
        }
        return false;
    }
};
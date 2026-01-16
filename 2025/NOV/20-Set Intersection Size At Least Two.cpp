class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
       
        int cnt=2;
        int ok=1;
        for(int i=1;i<intervals.size();++i){
                int x=intervals[i][0];
                int y=intervals[i][1];
                int last_x=intervals[i-1][0];
                int last_y=intervals[i-1][1];
                if(x<=last_y&&ok){
                    if(y<=last_y) continue;
                    else if(x==last_x) continue;
                    else cnt++;
                }else{
                    if(x==last_x) continue;
                    ok=1;
                    cnt+=2;
                }
        }
        return cnt;
    }
};

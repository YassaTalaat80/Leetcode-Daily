class Solution {
public:
    int maxOperations(string s) {
       int n=s.size();
        int ans=0,cnt=0,ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++,cnt++;
            else if(cnt>0) ans+=ones,cnt=0;
        }
        return ans;
    }
};

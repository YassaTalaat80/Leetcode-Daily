class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nn=strs.size();
        unordered_map<int,int> mp1,mp0;
        for(int i=0;i<nn;i++){
            int mm=strs[i].size();
            string s=strs[i];
            int cnt1=0,cnt0=0;
            for(int j=0;j<mm;j++){
                cnt1+=(s[j]=='1');
                cnt0+=(s[j]=='0');
            }
            mp1[i]=cnt1;
            mp0[i]=cnt0;
        }
vector<vector<vector<int>>> dp(nn, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        auto rec=[&](auto&&self,int i,int h1,int h2)->int{
            if(h1>n||h2>m) return -1e9;
                if(i==nn) return 0;
                int &ret=dp[i][h1][h2];
                if(~ret) return ret;
                ret=self(self,i+1,h1,h2);
                ret=max(ret,self(self,i+1,h1+mp1[i],h2+mp0[i])+1);
                return ret;
        };
        int ans=rec(rec,0,0,0);
        if(ans<=0) return 0;
        else return ans;
    }
};

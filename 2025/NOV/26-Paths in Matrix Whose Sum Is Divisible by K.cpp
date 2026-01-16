class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
    const int MOD=1e9+7;
        auto rec=[&](auto&&self,int i,int j,int mod)->int{
                if(i==n-1&&j==m-1) return ((mod+grid[i][j])%k)==0;

                int &ret=dp[i][j][mod];
                if(~ret) return ret;
                int ch1=0,ch2=0;
                if(i+1<n) ch1+=self(self,i+1,j,(mod+grid[i][j])%k);
                if(j+1<m) ch2+=self(self,i,j+1,(mod+grid[i][j])%k);
            
                return ret=(ch1+ch2)%MOD;
        };

        return rec(rec,0,0,0);
    };
};

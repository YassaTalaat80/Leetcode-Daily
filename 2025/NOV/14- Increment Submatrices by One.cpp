class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(int i=0;i<m;i++){
            vector<int> v=queries[i];
            int r1=v[0],c1=v[1],r2=v[2],c2=v[3];
                ans[r1][c1]+=1;
                if(r2+1<n) ans[r2+1][c1]-=1;
                if(c2+1<n) ans[r1][c2+1]-=1;
                if(r2+1<n&&c2+1<n) ans[r2+1][c2+1]+=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=0) ans[i][j]+=ans[i-1][j];
                if(j!=0) ans[i][j]+=ans[i][j-1];
                if(i!=0&&j!=0) ans[i][j]-=ans[i-1][j-1];
            }
        }
        return ans;
    }

};

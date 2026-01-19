class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int l) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> pre(m+1,vector<int> (n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    pre[i+1][j+1]=mat[i][j]-pre[i][j]+pre[i][j+1]+pre[i+1][j];
            }
        }
        int low = 1, high = min(m, n), ans = 0;
              auto can=[&](int k){
            for (int i = k; i < pre.size(); i++) {
            for (int j = k; j < pre[0].size(); j++) {
                int total = pre[i][j] - pre[i-k][j] - pre[i][j-k] + pre[i-k][j-k];
                if (total <= l) return true;
            }
        }
        return false;
        };
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
  
       
    }
};

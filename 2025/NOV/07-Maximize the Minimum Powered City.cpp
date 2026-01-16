class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=(int)stations.size();
       vector<long long> pre(n);
        for(int i=0;i<n;i++){
            if(!i){
                pre[i]=stations[i];
                continue;
            }
            pre[i]=pre[i-1]+stations[i];
        }
        long long li=0,ri=0,mid,ans=-1;
      vector<long long> pre2(n);
for (int i = 0; i < n; i++) {
    int l = max(0, i - r);
    int rr = min(n - 1, i + r);
    pre2[i] = pre[rr] - (l ? pre[l - 1] : 0);
    ri = max(ri, pre2[i]);
}

        ri+=k;
        
        auto can = [&](long long mid)->bool {
            vector<long long> diff(n, 0);
            long long used = 0; 
            long long add = 0;    
            for (int i = 0; i < n; i++) {
                add += diff[i];  
                long long current = pre2[i] + add;

                if (current < mid) {
                    long long need = mid - current;
                    if (need > k - used) return false; 
                    used += need;
                    add += need; 

                    int end = i + 2 * r + 1; 
                    if (end < n) diff[end] -= need; 
                }
            }
            return true;
        };
        while(li<=ri){
            mid=li+(ri-li)/2;
            if(can(mid)) {
                ans=mid;
                li=mid+1;
            }else ri=mid-1;
        }
        return ans;
    }
};

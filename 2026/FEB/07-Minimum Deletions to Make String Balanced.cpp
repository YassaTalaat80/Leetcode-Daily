
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        if(n==1) return 0;
        vector<int> pre(n,0),suf(n,0);
        
        for(int i=0;i<n;i++){
            if(i) pre[i]=pre[i-1];
            pre[i]+=(s[i]=='b');
        }
        for(int i=n-1;i>=0;--i){
            if(i!=n-1) suf[i]=suf[i+1];
            suf[i]+=(s[i]=='a');
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
    int x=0, y=0;
            if(i) x=pre[i-1];
            y=suf[i];
            ans=min(ans,x+y);
            int c=0,d=0;
            c=pre[i];
            if(i+1<n) d=suf[i+1];
            ans=min(ans,c+d);
        }
        return ans;
    }
};

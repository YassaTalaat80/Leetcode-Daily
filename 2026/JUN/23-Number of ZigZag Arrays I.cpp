int t[2001][2001][2];
const int M=1e9+7;
class Solution {
public:
    int N,L,R;
    int solve(int len,int num,int flag){
        if(num<L) return 0;
        if(num>R) return 0;
        if(len==N) return 1;
        int ans=0;
        if(t[len][num][flag]!=-1) return t[len][num][flag];
        if(flag==0){
            ans=(ans+(solve(len+1,num-1,1)%M+solve(len,num-1,0)%M)%M)%M;
        }
        else{
            ans=(ans+(solve(len+1,num+1,0)%M+solve(len,num+1,1)%M)%M)%M;
        }
        return  t[len][num][flag]= ans;
    }
    int zigZagArrays(int n, int l, int r) {
        N=n,L=l,R=r;
        int ans=0;memset(t,-1,sizeof(t));
        for(int i=l;i<=r;i++){
           ans=(ans+solve(1,i,0)%M)%M;
           ans=(ans+solve(1,i,1)%M)%M;
        }
        return ans;
    }
};

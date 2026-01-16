class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long ans=1;int length=1;
        while(length<=k){
            if(ans%k==0) return length;
            ans=(ans*10+1)%k;
            length++;
        }
        return -1;
    }
};

class Solution {
public:
    int binaryGap(int n) {
        int ans=0,lst=-1;
        for(int i=0;i<30;i++)
        {
                if(n>>i&1){
                    if(lst==-1) lst=i;
                    else ans=max(ans,i-lst),lst=i;
                }
        }
        return ans;
    }
};

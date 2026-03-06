class Solution{
    public:
    bool checkOnesSegment(string s){
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') {
                if(i>0&&s[i-1]=='0'&&cnt!=0) return false;
                cnt=1;
            }
        }
        return true;
    }
};

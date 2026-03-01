class Solution{
	public:
    int minPartitions(string n) {
	    int ans=0;
	    for(auto c:n){
		    ans=max(ans,c-'0');
		    if(ans==9) break;
	    }
    return ans;
    }
};

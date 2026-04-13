class Solution{
  public:
    int getMinDistance(vector<int>&num,int target,int start){
      int n=num.size();
      int ans=1e9;
      for(int i=0;i<n;i++){
        if(num[i]==target){
          ans=min(ans,abs(i-start));

        }
      }
      return ans;
    }
};

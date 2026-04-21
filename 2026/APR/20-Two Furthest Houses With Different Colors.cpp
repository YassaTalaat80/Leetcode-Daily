class Solution{
  public:
    int maxDistance(vector<int>& nums){
      int n=nums.size();
      int ans=0;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          if(nums[i]!=nums[j]){
              ans=max(ans,j-i);
          }
        }
      }
      return ans;
    }
};

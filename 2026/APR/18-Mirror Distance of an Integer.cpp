class Solution{
  public:
    int mirrorDistance(int n){
      int rev=0;
      int x=n;
      while(x){
        int last=x%10;
        rev=rev*10+last;
        x/=10;
      }
      return abs(n-rev);
    }
};



class Solution{
  public :
    long long INF=1e18;


    long long minimumTotalDistance(vector<int> robot,vector<vector<int>> factory){
      sort(robot.begin(),robot.end());
      sort(factory.begin(),factory.end());
      vector<int> s;
      for(int i=0;i<factory.size();i++){
        int pos=factory[i][0];
        int cap=factory[i][1];
        while(cap--){
          s.push_back(pos);
        }

      }
      vector<vector<long long>> dp(robot.size()+1,vector<long long>(s.size()+1,-1));

      auto rec=[&](auto &&rec,int i,int j)->long long{
        if(i>=robot.size()) return 0;
        if(j>=s.size()) return INF;

        long long  &ret= dp[i][j];
        if(~ret) return ret;

        long long take =abs(robot[i]-s[j])+rec(rec,i+1,j+1);
        long long nTake =rec(rec,i,j+1);
       return  ret=min(take,nTake);
      };
      return rec(rec,0,0);
    }
};

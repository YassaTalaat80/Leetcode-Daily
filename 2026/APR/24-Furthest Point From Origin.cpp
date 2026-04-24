class Solution{
  public :
    int furthestDistanceFromOrigin(string moves) {
     int l=0,r=0;
     int under=0;
     for(int i=0;i<moves.size();i++){
       if(moves[i]=='L') l++;
       else if(moves[i]=='R') r++;
       else under++;
     }
     int ans=0;
     if(l>=r){  
       ans=l-r;
       ans+=under;
     }
     else{
      ans=r-l;
      ans+=under;
     }
     return ans;
    }
};

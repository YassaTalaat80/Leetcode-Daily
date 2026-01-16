class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int m=neededTime.size();
        long long sum=0,j=0;
        for(int i=1;i<n;i++){
                while(i<n&&(colors[i]==colors[i-1])){
                        sum+=min(neededTime[i],neededTime[i-1]);
                        neededTime[i]=max(neededTime[i],neededTime[i-1]);
                        i++;
                }
        }
        return sum;
    }
};

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int mn=0;
        for(int i=0;i<n;i++){
            int x=nums[i]%3;
            int y=3-x;
            mn+=min(x,y);
        }
        return mn;
    }

};

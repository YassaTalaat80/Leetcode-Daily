class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return -1;
        unordered_map<int,int> mp;
        vector<int> v;
        int ans=1e9;
        unordered_map<int,deque<int>> mp2;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            mp2[nums[i]].push_back(i);
            if(mp[nums[i]]==3){
                deque<int> x=mp2[nums[i]];
                ans=min(ans,(x[1]-x[0])+(x[2]-x[1])+(x[2]-x[0]));
                mp2[nums[i]].pop_front();
                mp[nums[i]]--;
            }
        }
        return ans==1e9?-1:ans;
    }
};

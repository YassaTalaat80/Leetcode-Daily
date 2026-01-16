class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_map<int,int> pre,pre2;
        vector<vector<int>> v(26,vector<int>(3,0));
        int ans=0;
        for(int i=0;i<n;i++){
            if(pre[s[i]-'a']==0) pre[s[i]-'a']=i+1;
            pre2[s[i]-'a']=i+1;
        }
        for(int i=0;i<26;i++){
            unordered_map<int,int> mp;
            for(int j=pre[i];j<pre2[i]-1;j++){
                    mp[s[j]-'a']++;
            }
            ans+=mp.size();
        }
        return ans;
    }
};

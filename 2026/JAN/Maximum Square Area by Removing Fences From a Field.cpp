class Solution {
    const int mod =1e9+7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(n);
        vFences.push_back(1);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_map<int,int> mp;
        for (int i=0;i<hFences.size();i++) {
            for (int j=i+1;j<hFences.size();j++) {
                int x=hFences[j]-hFences[i];
                mp[x]=1;
            }
        }
        long long mx=0;
        for (int i=0;i<vFences.size();i++) {
            for (int j=i+1;j<vFences.size();j++) {
                int x=vFences[j]-vFences[i];
                if (mp.count(x))
                    mx=max(mx,x*1LL);
            }
        }

        return (mx==0?-1:(mx*mx)%mod);
    }
};

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> v;
        int mn=1e9;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]<mn) mn=(arr[i+1]-arr[i]);
        }
        int j=0;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==mn) {
                v.push_back({});
                v[j].push_back(arr[i]);
                v[j++].push_back(arr[i+1]);
            }
        }
        return v;
    }
};

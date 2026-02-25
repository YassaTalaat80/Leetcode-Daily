class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
	vector<vector<int>> v(32,vector<int>());
	for(int i=0;i<n;i++){
            
		int x=arr[i];
		int cnt=0;
		while(x){
                  if(x%2) cnt++;
		  x/=2;
		}
             v[cnt].push_back(arr[i]);
	    sort(v[cnt].begin(),v[cnt].end());
	}
	vector<int> ans;
	for(int i=0;i<32;i++){

		for(int j=0;j<v[i].size();j++){

			ans.push_back(v[i][j]);
		}
	}
	return ans;
    }
};

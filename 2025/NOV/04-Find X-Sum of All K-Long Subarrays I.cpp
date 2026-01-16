class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
       int n = nums.size();
    vector<int> answer;
    for (int i = 0; i <= n - k; i++) {
        vector<int> sub(nums.begin() + i, nums.begin() + i + k);
        unordered_map<int,int> freq;
        for (int num : sub) freq[num]++;

        vector<pair<int,int>> freqVec(freq.begin(), freq.end());

        sort(freqVec.begin(), freqVec.end(), [](pair<int,int>& a, pair<int,int>& b){
            if (a.second != b.second) return a.second > b.second;
            return a.first > b.first; 
        });
        int total=0;
        for (int j = 0; j < min(x, (int)freqVec.size()); j++){
                total+=(freqVec[j].first*freqVec[j].second);
        }
    answer.push_back(total);
    }

    return answer;
    }
};

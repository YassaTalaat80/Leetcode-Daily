class Solution {
public:
    vector<string> twoEditWords(vector<string>& quer, vector<string>& dict) {
        vector<string> ans;
        vector<pair<int, string>> v;
        for (int i = 0; i < quer.size(); i++) {
            for (int k = 0; k < dict.size(); k++) {
                if (dict[k].size() == quer[i].size()) {
                    int cnt = 0;
                    for (int j = 0; j < quer[i].size(); j++) {
                        if (quer[i][j] != dict[k][j]) {
                            cnt++;
                        }
                    }
                    if (cnt <= 2) {
                        ans.push_back(quer[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

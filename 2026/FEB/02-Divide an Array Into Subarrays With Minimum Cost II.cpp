class Solution {
public:
    long long minimumCost(vector<int> &nums, int k, int dist) {
        int n = nums.size();
        set<pair<int, int> > kMinimum;
        set<pair<int, int> > rem;
        long long sum = 0;

        int i = 1;
        while (i - dist < 1) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];
            if (kMinimum.size() > k - 1) {
                pair<int, int> temp = *kMinimum.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                kMinimum.erase(temp);
            }
            i++;
        }

        long long result = LONG_MAX;
        while (i < n) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if (kMinimum.size() > k - 1) {
                pair<int, int> temp = *kMinimum.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                kMinimum.erase(temp);
            }

            result = min(result, sum);

            pair<int, int> remove = {nums[i - dist], i - dist};
            if (kMinimum.count(remove)) {
                kMinimum.erase(remove);
                sum -= remove.first;

                if (!rem.empty()) {
                    pair<int, int> temp = *rem.begin();
                    kMinimum.insert(temp);
                    sum += temp.first;
                    rem.erase(temp);
                }
            } else rem.erase(remove);

            i++;
        }
        return result + nums[0];
    }
};

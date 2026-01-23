
class Solution {
public:
    int minimumPairRemoval(vector<int> &nums1) {
        int n = nums1.size();
        vector<int> nextIndex(n), prevIndex(n);
        vector<long long > nums(n);
        for (int i = 0; i < n; i++) {
            nums[i]=nums1[i];
            nextIndex[i] = i + 1;
            prevIndex[i] = i - 1;
        }
        set<pair<long long,int> > s;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])cnt++;
            s.insert({nums[i] + nums[i + 1], i});
        }
        int ans = 0;
        while (cnt > 0) {
            auto it = s.begin();
            int currIdx = it->second;
            int nextIdx = nextIndex[currIdx];
            int prevIdx = prevIndex[currIdx];
            int nextNextIdx = nextIndex[nextIdx];
            s.erase(it);
            if (nums[currIdx] > nums[nextIdx])cnt--;
            if (prevIdx >= 0) {
                if (nums[prevIdx] > nums[currIdx]) cnt--;
                if (nums[prevIdx] > nums[currIdx] + nums[nextIdx]) cnt++;
                s.erase({nums[prevIdx] + nums[currIdx], prevIdx});
            }
            if (nextNextIdx < n) {
                if (nums[nextIdx] > nums[nextNextIdx]) cnt--;
                if (nums[currIdx] + nums[nextIdx] > nums[nextNextIdx]) cnt++;
                s.erase({nums[nextIdx] + nums[nextNextIdx], nextIdx});
            }
            nums[currIdx] = nums[currIdx] + nums[nextIdx];
            nextIndex[currIdx] = nextNextIdx;
            if (nextNextIdx < n) prevIndex[nextNextIdx] = currIdx;

            if (prevIdx >= 0) {
                s.insert({nums[prevIdx] + nums[currIdx], prevIdx});
            }

            if (nextNextIdx < n) {
                s.insert({nums[currIdx] + nums[nextNextIdx], currIdx});
            }
            ans++;
        }
        return ans;
    }
};

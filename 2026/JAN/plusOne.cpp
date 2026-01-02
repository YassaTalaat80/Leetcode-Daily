
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        int ok = 0;
        vector<int> ans;
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0, ok = 1;
            else {
                digits[i] += 1, ok = 0;
                break;
            }
        }
        if (ok == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) b = string(a.size() - b.size(), '0') + b;
        else if (a.size() < b.size()) a = string(b.size() - a.size(), '0') + a;
        
        int cnt = 0;
        string s = "";
        
        for (int i = a.size() - 1; i >= 0 || cnt; i--) {
            if (i >= 0) {
                if (a[i] == b[i]) {
                    if (a[i] == '1') {
                        if (cnt) s += '1'; 
                        else s += '0';
                        cnt = 1;
                    } else {
                        s += (char)(cnt + '0'); 
                        cnt = 0;
                    }
                } else {
                    if (cnt) {
                        s += '0';
                        cnt = 1;
                    } else {
                        s += '1';
                        cnt = 0;
                    }
                }
            } else {
                s += (cnt + '0');
                cnt = 0;
            }
        } 
        reverse(s.begin(), s.end());
        return s;
    }
};

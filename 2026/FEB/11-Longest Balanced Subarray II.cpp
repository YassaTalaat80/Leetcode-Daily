typedef long long ll;

struct Node {
    int mn = 1e9, mx = -1e9;
    int lazy = 0;

    Node() {}
    Node(int x) : mn(x), mx(x) {}

    void add(int x) {
        mn += x;
        mx += x;
        lazy += x;
    }
};

struct Sagara {
    int n;
    vector<Node> node;

    Sagara(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        node.assign(n * 2, Node(0));
    }

    Node merge(const Node &l, const Node &r) {
        Node res;
        res.mn = min(l.mn, r.mn);
        res.mx = max(l.mx, r.mx);
        return res;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1 || node[x].lazy == 0) return;
        node[x * 2 + 1].add(node[x].lazy);
        node[x * 2 + 2].add(node[x].lazy);
        node[x].lazy = 0;
    }

    void update(int l, int r, int val, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            node[x].add(val);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        update(l, r, val, x * 2 + 1, lx, m);
        update(l, r, val, x * 2 + 2, m, rx);
        node[x] = merge(node[x * 2 + 1], node[x * 2 + 2]);
    }

    void update(int l, int r, int val) { if (l < r) update(l, r, val, 0, 0, n); }

    int find_first(int l, int r, int target, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l || target < node[x].mn || target > node[x].mx) return -1;
        if (rx - lx == 1) return lx;
        int m = (lx + rx) / 2;
        int res = find_first(l, r, target, x * 2 + 1, lx, m); 
        if (res == -1) res = find_first(l, r, target, x * 2 + 2, m, rx);
        return res;
    }

    int find_first(int l, int r, int target) { return find_first(l, r, target, 0, 0, n); }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        Sagara st(n + 1); 
        unordered_map<int, int> last_seen;
        int maxLen = 0;

        for (int r = 0; r < n; r++) {
            int val = (nums[r] % 2 == 0) ? 1 : -1;
            
            int prev_pos = last_seen.count(nums[r]) ? last_seen[nums[r]] : -1;
            st.update(prev_pos + 1, r + 1, val);
            int first_l = st.find_first(0, r + 1, 0);
            
            if (first_l != -1) {
                maxLen = max(maxLen, r - first_l + 1);
            }

            last_seen[nums[r]] = r;
        }

        return maxLen;
    }
};

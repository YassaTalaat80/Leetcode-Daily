#include <bits/stdc++.h>
using namespace std;

using ll = long long;



struct Node {
    int cover = 0;   
    ll val = 0;       
};

#define lNode (x * 2 + 1)
#define rNode (x * 2 + 2)
#define md ((lx + rx) / 2)

struct SegTree {
    int n;
    vector<Node> tree;
    vector<ll> *coord;  
    SegTree(int sz, vector<ll> &c) {
        coord = &c;
        n = 1;
        while (n < sz) n <<= 1;
        tree.assign(2 * n, Node());
    }

    Node merge(const Node &L, const Node &R) {
        Node res;
        res.val = L.val + R.val;
        return res;
    }

    void pull(int x, int lx, int rx) {
        if (tree[x].cover > 0) {
            tree[x].val = (*coord)[rx] - (*coord)[lx];
        } else if (rx - lx == 1) {
            tree[x].val = 0;
        } else {
            tree[x].val = tree[lNode].val + tree[rNode].val;
        }
    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;

        if (lx >= l && rx <= r) {
            tree[x].cover += v;
            pull(x, lx, rx);
            return;
        }

        update(l, r, v, lNode, lx, md);
        update(l, r, v, rNode, md, rx);
        pull(x, lx, rx);
    }

    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, n);
    }

    ll query() {
        return tree[0].val; 
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        struct Event {
            ll y, x1, x2;
            int type;
            bool operator<(const Event &o) const {
                return y < o.y;
            }
        };

        vector<Event> events;
        vector<ll> xs;

        for (auto &s : squares) {
            ll x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(events.begin(), events.end());
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        int m = xs.size();
        SegTree seg(m, xs);

        auto getX = [&](ll v) {
            return lower_bound(xs.begin(), xs.end(), v) - xs.begin();
        };

        vector<pair<double, double>> slabs;
        double totalArea = 0.0;

        for (int i = 0; i + 1 < events.size(); i++) {
            int l = getX(events[i].x1);
            int r = getX(events[i].x2);
            seg.update(l, r, events[i].type);

            double h = (double)(events[i + 1].y - events[i].y);
            if (h > 0) {
                double w = (double)seg.query();
                slabs.push_back({h, w});
                totalArea += h * w;
            }
        }

        double half = totalArea / 2.0;
        double cur = 0.0;
        double curY = events[0].y;

        for (auto &s : slabs) {
            double area = s.first * s.second;
            if (cur + area >= half) {
                return curY + (half - cur) / s.second;
            }
            cur += area;
            curY += s.first;
        }

        return curY;
    }
};



struct Robot {
    int id;
    int pos;
    int health;
    char dir;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);

        for (int i = 0; i < n; ++i) {
            robots[i] = {i, positions[i], healths[i], directions[i]};
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        stack<Robot> st;
        for (auto& current : robots) {
            if (current.dir == 'R') {
                st.push(current);
            } else {
                while (!st.empty() && st.top().dir == 'R' && current.health > 0) {
                    if (st.top().health < current.health) {
                        st.pop();
                        current.health -= 1;
                    } else if (st.top().health > current.health) {
                        st.top().health -= 1;
                        current.health = 0;
                    } else {
                        st.pop();
                        current.health = 0;
                    }
                }
                if (current.health > 0) {
                    st.push(current);
                }
            }
        }

        vector<Robot> survivors;
        while (!st.empty()) {
            survivors.push_back(st.top());
            st.pop();
        }

        sort(survivors.begin(), survivors.end(), [](const Robot& a, const Robot& b) {
            return a.id < b.id;
        });

        vector<int> result;
        for (const auto& r : survivors) {
            result.push_back(r.health);
        }

        return result;
    }
};

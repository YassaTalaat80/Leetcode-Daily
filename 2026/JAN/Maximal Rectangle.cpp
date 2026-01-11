class Solution {
public:
    int area(vector<int> &heights) {
        stack<int> s;
        heights.push_back(0);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                max_area = max(max_area, h * w);
            }
            s.push(i);
        }
        heights.pop_back();
        return max_area;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            max_area = max(max_area, area(heights));
        }
        return max_area;
    }
};

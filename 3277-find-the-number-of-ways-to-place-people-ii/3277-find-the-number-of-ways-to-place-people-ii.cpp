bool compare(vector<int>& v1, vector<int>& v2) {
    if (v1[0] == v2[0])
        return v1[1] > v2[1];
    return v1[0] < v2[0];
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            int ymax = INT_MIN;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][1] > ymax && points[j][1]<=points[i][1]) {
                    res++;
                    ymax = points[j][1];
                }
            }
        }
        return res;
    }
};
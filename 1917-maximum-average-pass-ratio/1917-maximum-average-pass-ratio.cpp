class Solution {
public:
    double diff(int p, int n) {
        double res = ((double)n - (double)p) / ((double)n * (1 + (double)n));
        return res;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++) {
            pq.push({diff(classes[i][0], classes[i][1]), i});
        }
        for (int i = 1; i <= extraStudents; i++) {
            pair<double, int> p = pq.top();
            pq.pop();
            int idx = p.second;
            classes[idx][0]++, classes[idx][1]++;
            pq.push({diff(classes[idx][0], classes[idx][1]), idx});
        }
        double res = 0;
        for (int i = 0; i < classes.size(); i++) {
            res += ((double)classes[i][0] / (double)classes[i][1]);
        }
        res /= (double)(classes.size());
        return (res * 1e5) / 1e5;
    }
};
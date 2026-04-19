bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[2]>v2[2];
}

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> res(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        sort(sources.begin(),sources.end(),&cmp);
        for (int i = 0; i < sources.size(); i++) {
            int r = sources[i][0], c = sources[i][1];
            res[r][c] = sources[i][2];
            q.push({r, c});
        }
        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            if (r-1>=0 && res[r - 1][c] == 0) {
                res[r - 1][c] = res[r][c];
                q.push({r - 1, c});
            }
            if (r+1<n && res[r + 1][c] == 0) {
                res[r + 1][c] = res[r][c];
                q.push({r + 1, c});
            }
            if (c-1>=0 && res[r][c - 1] == 0) {
                res[r][c - 1] = res[r][c];
                q.push({r, c - 1});
            }
            if (c+1<m && res[r][c + 1] == 0) {
                res[r][c + 1] = res[r][c];
                q.push({r, c + 1});
            }
        }
        return res;
    }
};
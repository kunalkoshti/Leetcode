int mod = 1e9 + 7;
class Solution {
public:
    void buildt(vector<vector<int>>& t, int m) {
        for (int c = 1; c < m; c++) {
            for (int j = 0; j < c; j++) {
                t[m + j][c] = 1;
            }
        }
        for (int c = m; c < 2 * m - 1; c++) {
            for (int j = c - m + 1; j < m; j++) {
                t[j][c] = 1;
            }
        }
        return;
    }
    vector<vector<int>> matrix_mul(vector<vector<int>>& v1,
                                   vector<vector<int>>& v2) {
        if (v1.size() == 0 || v2.size() == 0)
            return {};
        int r1 = v1.size(), c1 = v1[0].size();
        int r2 = v2.size(), c2 = v2[0].size();
        if (c1 != r2)
            return {};
        vector<vector<int>> res(r1, vector<int>(c2, 0));
        for (int r = 0; r < r1; r++) {
            for (int c = 0; c < c2; c++) {
                for (int i = 0; i < r2; i++) {
                    res[r][c] = ((long long)res[r][c] +
                                 ((long long)v1[r][i] * v2[i][c]) % mod) %
                                mod;
                }
            }
        }
        return res;
    }
    vector<vector<int>> exp(vector<vector<int>> v, int p) {
        if (p == 1)
            return v;
        vector<vector<int>> t;
        if (p % 2 == 0) {
            t = exp(v, p / 2);
            return matrix_mul(t, t);
        }
        t = exp(v, p - 1);
        return matrix_mul(t, v);
    }
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<vector<int>> t(2 * m, vector<int>(2 * m, 0));
        buildt(t, m);
        vector<vector<int>> ini(1, vector<int>(2 * m, 1));
        vector<vector<int>> trans = exp(t, n - 1);
        vector<vector<int>> v = matrix_mul(ini, trans);
        int res = 0;
        for (int i = 0; i < 2 * m; i++) {
            res = (res + (long long)v[0][i]) % mod;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int vs = words.size();
        int ws = words[0].size();
        if (n < (vs * ws))
            return {};
        vector<int> res;
        unordered_map<string, int> target;
        for (int i = 0; i < vs; i++) {
            if (target.find(words[i]) == target.end())
                target[words[i]] = 1;
            else
                target[words[i]]++;
        }
        for (int j = 0; j < ws; j++) {
            unordered_map<string, int> state;
            int window = 0;
            for (int i = j; i < n; i += ws) {
                if (i + ws - 1 >= n)
                    break;
                string curr = string(string_view(s).substr(i, ws));
                if (target.find(curr) == target.end()) {
                    state.clear();
                    window = 0;
                    continue;
                }
                if (state.find(curr) == state.end())
                    state[curr] = 1;
                else
                    state[curr]++;
                window++;
                int start = i - (window - 1) * ws;
                while (start <= i && state[curr] > target[curr]) {
                    string tmp = string(string_view(s).substr(start, ws));
                    state[tmp]--;
                    start += ws;
                    window--;
                }
                if (state[curr] == target[curr] && window == vs) {
                    res.push_back(start);
                }
            }
        }

        return res;
    }
};
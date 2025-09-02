#define ll long long
struct Ele {
    int limit, value;
};

struct Compare {
    bool operator()(const Ele& a, const Ele& b) const {
        if (a.limit == b.limit) {
            return a.value < b.value; // max value first
        }
        return a.limit > b.limit; // min limit first
    }
};

class Solution {
public:
    int update(vector<int>& active, int ca,int inactive) {
        auto it = upper_bound(active.begin()+inactive, active.end(), ca);
        if (it == active.begin())
            return active.size();
        return active.end() - it;
    }
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        priority_queue<Ele, vector<Ele>, Compare> pq;
        for (int i = 0; i < value.size(); i++) {
            pq.push({limit[i], value[i]});
        }
        vector<int> active;
        int ca = 0;
        ll res = 0;
        int inactive = 0;
        while (!pq.empty()) {
            Ele curr = pq.top();
            pq.pop();
            int lim = curr.limit, val = curr.value;
            ca++;
            res += (ll)val;
            active.push_back(lim);
            while (!pq.empty() && pq.top().limit <= ca) {
                pq.pop();
            }
            cout << ca << " ";
            int prev_ca = ca;
            ca = update(active, ca,inactive);
            inactive = inactive+prev_ca - ca;
            cout << ca << endl;
        }
        return res;
    }
};
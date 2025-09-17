const int max_heap_size = 2 * 1e4;
bool isLexicographicallySmaller(const string& s1, const string& s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int n = min(n1, n2);

    // Compare character by character
    for (int i = 0; i < n; i++) {
        if (s1[i] < s2[i])
            return true; // s1 is smaller
        if (s1[i] > s2[i])
            return false; // s1 is larger
    }

    // If all characters matched so far, shorter string is smaller
    return n1 < n2;
}

class Heap {
    vector<pair<int, string>> heap;
    int itr;

public:
    Heap() {
        heap.resize(max_heap_size + 1);
        itr = 0;
    }
    // par i -> 2*i , 2*i+1
    string top() { return heap[1].second; }

    void push(pair<int, string> p, unordered_map<string, int>& mp) {
        if (itr == max_heap_size) {
            cout << "Heap is full" << endl;
            return;
        }
        itr++;
        heap[itr] = p;
        mp[p.second] = itr;
        move_up(itr, mp);
    }
    void move_up(int idx, unordered_map<string, int>& mp) {
        if (idx == 1)
            return;
        int parent = idx / 2;
        if (heap[parent].first > heap[idx].first)
            return;
        if (heap[parent].first == heap[idx].first &&
            isLexicographicallySmaller(heap[parent].second, heap[idx].second))
            return;
        pair<int, string> temp = heap[parent];
        heap[parent] = heap[idx];
        heap[idx] = temp;
        mp[heap[idx].second] = idx;
        mp[heap[parent].second] = parent;
        move_up(parent, mp);
    }

    void move_down(int idx, unordered_map<string, int>& mp) {
        if (idx > itr)
            return;
        int ch1 = idx * 2, ch2 = ch1 + 1;
        if (ch1 > itr)
            return;
        int sc = ch1, vc = heap[sc].first;
        if (ch2 <= itr && (heap[ch2].first > vc ||
                           (heap[ch2].first == vc &&
                            isLexicographicallySmaller(heap[ch2].second,
                                                       heap[ch1].second)))) {
            sc = ch2;
            vc = heap[ch2].first;
        }
        if (heap[idx].first > vc ||
            (heap[idx].first == vc &&
             isLexicographicallySmaller(heap[idx].second, heap[sc].second)))
            return;
        pair<int, string> temp = heap[idx];
        heap[idx] = heap[sc];
        heap[sc] = temp;
        mp[heap[idx].second] = idx;
        mp[heap[sc].second] = sc;
        move_down(sc, mp);
    }

    void changeRating(int idx, int nr, unordered_map<string, int>& mp) {
        heap[idx].first = nr;
        move_up(idx, mp);
        move_down(idx, mp);
    }
};

class FoodRatings {
    unordered_map<string, Heap*> cus; // map of cus and heap
    unordered_map<string, int> food;  // idx of food in heap
    unordered_map<string, string> fc; // food cuisine map
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string f = foods[i];
            string c = cuisines[i];
            int r = ratings[i];
            if (cus.find(c) == cus.end()) {
                cus[c] = new Heap();
            }
            cus[c]->push({r, f}, food);
            fc[f] = c;
        }
    }

    void changeRating(string food_, int newRating) {
        string c = fc[food_];
        int idx = food[food_];
        cus[c]->changeRating(idx, newRating, food);
    }

    string highestRated(string cuisine) { return cus[cuisine]->top(); }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
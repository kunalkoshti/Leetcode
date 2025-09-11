bool comp(char c1, char c2) { return c1 - 'A' < c2 - 'A'; }
class Solution {
public:
    bool isVowel(char c) {
        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||
            c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
            return true;
        return false;
    }
    string sortVowels(string s) {
        vector<char> v;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i]))
                v.push_back(s[i]);
        }
        sort(v.begin(), v.end(), comp);
        int itr = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = v[itr];
                itr++;
            }
        }
        return s;
    }
};
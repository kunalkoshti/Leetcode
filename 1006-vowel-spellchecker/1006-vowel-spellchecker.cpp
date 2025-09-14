class Solution {
public:
     bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string maskVowels(const string& word) {
        string res = word;
        for (char& c : res) {
            if (isVowel(c)) c = '*';
            else c = tolower(c);
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
         unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        // preprocess wordlist
        for (string& w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = w;

            string masked = maskVowels(w);
            if (!vowelInsensitive.count(masked))
                vowelInsensitive[masked] = w;
        }

        vector<string> res;
        for (string& q : queries) {
            if (exact.count(q)) {
                res.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (caseInsensitive.count(lower)) {
                res.push_back(caseInsensitive[lower]);
                continue;
            }

            string masked = maskVowels(q);
            if (vowelInsensitive.count(masked)) {
                res.push_back(vowelInsensitive[masked]);
                continue;
            }

            res.push_back("");
        }
        return res;
    }
};
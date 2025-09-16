class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (int i = 0; i < brokenLetters.size(); i++) {
            broken[brokenLetters[i] - 'a'] = true;
        }
        string curr = "";
        bool isbroken = false;
        int res = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                if (!isbroken)
                    res++;
                curr = "";
                isbroken = false;
            } else {
                if (broken[text[i] - 'a'])
                    isbroken = true;
                curr += text[i];
            }
        }
        if (!isbroken)
            res++;
        return res;
    }
};
class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int ct=0;
        for(int i=0;i<s.length();i++)
        {
            if(isVowel(s[i]))ct++;
        }
        return ct!=0;
    }
};
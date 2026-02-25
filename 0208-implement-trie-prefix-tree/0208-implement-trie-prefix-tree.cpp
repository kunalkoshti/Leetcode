const int K=26;
struct Vertex{
    int next[K];
    bool output=false;
    Vertex(){
        fill(begin(next),end(next),-1);
    }
};

class Trie {
    vector<Vertex> trie;
public:
    Trie() {
        trie.emplace_back();
    }

    void insert(string word) {
        int v=0;
        for(char ch:word){
            int c=ch-'a';
            if(trie[v].next[c]==-1){
                trie[v].next[c]=trie.size();
                trie.emplace_back();
            }
            v=trie[v].next[c];
        }
        trie[v].output=true;
    }

    bool search(string word) {
        int v=0;
        for(char ch:word){
            int c=ch-'a';
            if(trie[v].next[c]==-1) return false;
            v=trie[v].next[c];
        }
        return trie[v].output;
    }

    bool startsWith(string prefix) {
        int v=0;
        for(char ch:prefix){
            int c=ch-'a';
            if(trie[v].next[c]==-1) return false;
            v=trie[v].next[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
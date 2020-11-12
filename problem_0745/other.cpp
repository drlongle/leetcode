class TrieNode{
private:
    vector<int> in;

public:
    TrieNode* next[26];

    TrieNode() {
        memset(next,0,sizeof(next));
    }

    void insert(int num){
        in.push_back(num);
    }

    vector<int> get(){
        return in;
    }

};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string s,int num){
        TrieNode* p = root;
        p->insert(num);
        for(int i=0;i<s.size();i++){
            if(p->next[s[i]-'a'] == NULL) p->next[s[i]-'a'] = new TrieNode();
            p = p->next[s[i]-'a'];
            p->insert(num);
        }
    }

    vector<int> find(string s){
        TrieNode* p = root;
        for(int i=0;i<s.size();i++){
            if(p->next[s[i]-'a'] == NULL) return vector<int>{};
            p = p->next[s[i]-'a'];
        }
        return p->get();
    }
};

class WordFilter {
public:
    Trie pre,suf;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            pre.insert(words[i],i);
            reverse(words[i].begin(),words[i].end());
            suf.insert(words[i],i);
        }
    }

    int f(string prefix, string suffix) {
        reverse(suffix.begin(),suffix.end());
        vector<int> first = pre.find(prefix);
        vector<int> second = suf.find(suffix);
        int n = first.size()-1;
        int m = second.size()-1;

        while(n >= 0 and m >= 0){
            if(first[n] == second[m]) return first[n];
            if(first[n] > second[m]) n--;
            else m--;
        }
        return -1;
    }
};

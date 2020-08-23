class Trie_node{
public:
    vector<Trie_node *> next;
    bool end;
    Trie_node()
    {
        next = std::vector<Trie_node *>(26,NULL);
        end = false;
    }
};

class Trie
{
public:
    Trie_node *root;
    Trie(){
        root = new Trie_node();
    }

    /** Inserts a word into the trie. */
    void insert(string &word) {
        Trie_node *node = root;
        for(char c : word)
        {
            if(node ->next[c - 'a'] == NULL)
                node ->next[c - 'a'] = new Trie_node();
            node = node ->next[c - 'a'];
        }
        node->end = true;
    }

    bool check(deque<char> &dq){
        Trie_node *node = root;
        auto ptr = dq.rbegin();
        while(ptr != dq.rend()){
            if(node->next[*ptr - 'a'] == NULL)
                return false;
            node = node->next[*ptr - 'a'];
            if(node->end)
                return true;
            ptr ++;
        }
        return false;
    }
};

class StreamChecker {
private:
    Trie *helper;
    deque<char> dq;
    int max_s;
public:
    StreamChecker(vector<string>& words) {
        max_s = 0;
        for(string &s: words){
            max_s = max(max_s, (int)s.size());
            reverse(s.begin(), s.end());
        }
        helper = new Trie();
        for(auto &s: words)
            helper->insert(s);
    }

    bool query(char letter) {
        dq.push_back(letter);
        if(dq.size() > max_s){
            dq.pop_front();
        }
        return helper->check(dq);
    }
};

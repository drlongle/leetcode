class Solution {
public:
    struct Node{
        Node* children[26] ={0};
        bool isLeaf = false;
        void add(const string& str, int i) {
            if(i == str.size()) {
                isLeaf = true;
                return;
            }
            char ch = str[i];
            Node* child = children[ch - 'a'];
            if(child == nullptr) {
                child = children[ch - 'a'] = new Node();
            }
            child->add(str,i+1);
        }
        Node* find(char ch) {
            return children[ch - 'a'];
        }
        ~Node(){
            for(auto& child : children){
                if(child != nullptr) {
                    delete child;
                    child = nullptr;
                }
            }
        }

    };
    struct Trie{
        Node root;
        void add(const string& str) {
            int i = 0;
            root.add(str,i);
        }
        Node* find(char ch) {
            return root.find(ch);
        }
    };
    void push_interval(list<pair<int,int>>& intervals, pair<int,int> interval) {
        while(intervals.size()){
            auto& tmp = intervals.back();
            if(interval.first<=tmp.second+1){
                interval.first = min(tmp.first,interval.first);
                intervals.pop_back();
            } else {
                break;
            }
        }
        intervals.push_back(interval);

    }
    string boldWords(vector<string>& words, string S) {
        Trie trie;
        for(string& str : words){
            trie.add(str);
        }
        list<pair<int,int>> intervals;
        vector<pair<int,Node*>> nodes;
        for(int i = 0;i<S.size();i++) {
            char ch = S[i];
            for(auto ptr = nodes.begin();ptr!=nodes.end();){
                if(ptr->second->find(ch) == nullptr){
                    ptr = nodes.erase(ptr);
                } else {
                    ptr->second = ptr->second->find(ch);
                    if(ptr->second->isLeaf){
                        push_interval(intervals,{ptr->first,i});
                    }
                    ptr++;
                }
            }
            Node* node = trie.find(S[i]);
            if(node != nullptr) {
                if(node->isLeaf){
                    push_interval(intervals,{i,i});
                }
                nodes.push_back({i,node});
            }
        }
        if(intervals.empty()) {
            return S;
        }
        string ret = S.substr(0,intervals.front().first);
        for(auto ptr = intervals.begin();ptr!=intervals.end();ptr++){
            auto& interval = *ptr;
            ret += "<b>" + S.substr(interval.first, interval.second - interval.first + 1) + "</b>";
            if(next(ptr,1) != intervals.end()){
                auto& nextInterval = *(next(ptr,1));
                ret += S.substr(interval.second+1,nextInterval.first - interval.second - 1);
            } else {
                ret += S.substr(interval.second+1,S.size() - interval.second);
            }
        }
        return ret;
    }
};

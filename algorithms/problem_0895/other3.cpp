class FreqStack {
public:
    map<int, vector<int>> m1;
    unordered_map<int, int> m2;

    void push(int x) {
        m2[x]++;
        m1[m2[x]].push_back(x);
    }

    int pop() {
        auto iter = m1.rbegin();
        int ret = iter->second[(iter->second).size()-1];
        iter->second.pop_back();
        m2[ret]--;
        if(iter->second.size()==0)m1.erase(iter->first);
        return ret;
    }
};

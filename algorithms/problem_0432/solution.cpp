class AllOne {
  public:
    AllOne() {}

    void inc(string key) {
        int v;
        if (lookup.count(key)) {
            v = lookup[key];
            auto &s = reversed_lookup[v];
            s.erase(key);
            if (s.empty())
                reversed_lookup.erase(v);
        } else {
            v = 0;
        }
        v++;
        lookup[key] = v;
        reversed_lookup[v].insert(key);
    }

    void dec(string key) {
        int v;
        if (lookup.count(key)) {
            v = lookup[key];
            auto &s = reversed_lookup[v];
            s.erase(key);
            if (s.empty())
                reversed_lookup.erase(v);
        } else {
            v = 0;
        }
        v--;
        if (v != 0) {
            lookup[key] = v;
            reversed_lookup[v].insert(key);
        } else
            lookup.erase(key);
    }

    string getMaxKey() {
        if (lookup.empty())
            return "";
        auto it = reversed_lookup.rbegin();
        auto &s = it->second;
        return *s.begin();
    }

    string getMinKey() {
        if (lookup.empty())
            return "";
        auto it = reversed_lookup.begin();
        auto &s = it->second;
        return *s.begin();
    }

    map<string, int> lookup;
    map<int, set<string>> reversed_lookup;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

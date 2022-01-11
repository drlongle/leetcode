class LogSystem {
public:
    LogSystem() {
        // To get the substring indexes from the query string, used for granularity.
        mp["Year"] = 4;
        mp["Month"] = 7;
        mp["Day"] = 10;
        mp["Hour"] = 13;
        mp["Minute"] = 16;
        mp["Second"] = 19;

        // assign values to maxi and mini.
        maxi = "2017:12:31:23:59:59";
        mini = "2000:01:01:00:00:00";
    }

    void put(int id, string timestamp) {
        hashtable.insert({ timestamp, id });
    }

    vector<int> retrieve(string start, string end, string granularity) {
        int idx = mp.find(granularity)->second;
        string st = start.substr(0, idx) + mini.substr(idx);
        string en = end.substr(0, idx) + maxi.substr(idx);

        // To get the range of values within the specified timestamp, inclusive of end and start.
        auto it_start = hashtable.lower_bound(st);
        auto it_end = hashtable.upper_bound(en);

        // Vector to return.
        vector<int> ans;
        for(auto it = it_start; it != it_end; it++)
            ans.push_back(it->second);

        return ans;
    }

private:
    multimap<string, int> hashtable;
    unordered_map<string, int> mp;
    string maxi;
    string mini;
};

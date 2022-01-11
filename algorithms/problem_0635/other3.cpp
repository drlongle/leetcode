class LogSystem {
public:
    map<string, vector<int>> logs;
    map<string, int> gran = {{"Year", 4},
                             {"Month", 7},
                             {"Day", 10},
                             {"Hour", 13},
                             {"Minute", 16},
                             {"Second", 19}};

    LogSystem() {

    }

    void put(int id, string timestamp) {
        logs[timestamp].push_back(id);
    }

    vector<int> retrieve(string start, string end, string granularity) {
        int len = gran[granularity];
        vector<int> ids;

        for (auto& kv : logs) {
            if (kv.first.substr(0, len) < start.substr(0, len)) continue;
            if (kv.first.substr(0, len) > end.substr(0, len)) break;

            ids.insert(ids.end(), kv.second.begin(), kv.second.end());
        }

        return ids;
    }
};

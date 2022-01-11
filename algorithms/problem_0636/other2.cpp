class Log {
public:
    int id, timestamp;
    string type;

    Log(string log) {
        stringstream ss(log);
        string temp;

        getline(ss, temp, ':'), id = stoi(temp);
        getline(ss, temp, ':'), type = temp;
        getline(ss, temp, ':'), timestamp = stoi(temp);
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<Log> s;

        for (auto log : logs) {
            Log curLog(log);

            if (curLog.type == "start") {
                s.push(curLog);
                continue;
            }

            auto& startLog = s.top(); s.pop();
            int timeTaken = curLog.timestamp - startLog.timestamp + 1;
            result[curLog.id] += timeTaken;

            if (!s.empty()) {
                auto& parent = s.top();
                result[parent.id] -= timeTaken;
            }
        }

        return result;
    }
};

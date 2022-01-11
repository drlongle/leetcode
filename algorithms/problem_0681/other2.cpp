class Solution {
public:
    int diff1;
    string candidate;
    int diff2;
    string nextday;
    unordered_set<char> valid;

    string nextClosestTime(string time) {
        for (auto c: time){
            if (isdigit(c)){
                valid.insert(c);
            }
        }
        diff1 = INT_MAX;
        candidate = time;
        diff2 = INT_MAX;
        nextday = time;
        dp(time, "");
        return (diff1 == INT_MAX) ? nextday: candidate;
    }

    int compute(string time){
        return ((time[0] - '0')* 10 + (time[1] - '0')) * 60 +
        (time[3] - '0')* 10 + (time[4] - '0');
    }

    void dp(string time, string path){
        if (path.length() == 5){
            int cur = compute(path);
            int d = cur - compute(time);
            if (d > 0 and d < diff1){
                diff1 = d;
                candidate = path;
            }
            if (d < 0 and cur < diff2){
                diff2 = cur;
                nextday = path;
            }
            return;
        }
        if (path.length() == 1 and path[0] > '2') return;
        if (path.length() == 2 and path[0] == '2' and path[1] > '3') return;
        if (path.length() == 2) path += ":";
        if (path.length() == 4 and path[3] > '5') return;
        for (auto c: valid){
            dp(time, path + c);
        }
    }
};

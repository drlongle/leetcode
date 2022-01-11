class Solution {
public:
    vector<char> max_per_digit(const string &time) {
        int abs_max[] = {'2','3',':','5','9'};
        vector<char> max_allowed(5,0);
        for(auto c:time) {
            for(int i = 0; i < 5;i++)
                if(abs_max[i] != ':' && c <= abs_max[i] && c > max_allowed[i])
                    max_allowed[i] = c;
        }
        if(time[0] < '2')
            max_allowed[1] = max_allowed[4];

        return max_allowed;
    }

    string nextClosestTime(string time) {
        set<char> char_set{time.begin(), time.end()};
        char min_digit = *char_set.begin();
        vector<char> max_allowed = max_per_digit(time);

        int idx = 4;
        for(idx=4 ; idx >= 0 && (time[idx] == max_allowed[idx] || time[idx] == ':'); idx--)
            if(time[idx] != ':')
                time[idx] = min_digit;

            if(idx < 0)
                return string{min_digit} + min_digit + ":" + min_digit + min_digit;

            time[idx] = *char_set.upper_bound(time[idx]);
            return time;
    }
};

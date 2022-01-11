class Solution {
public:
    string addBoldTag(string s, vector& dict_wds) {
        unordered_set dict;
        for (auto wd : dict_wds) { dict.insert(wd); }

        typedef pair<int, int> Interval;
        vector<Interval> intervals;
        // This can be optimized using trie.
        for (int i = 0; i < s.size(); i++) {
            string cur_wd = "";
            for (int j = i; j < s.size(); j++) {
                cur_wd.append(1, s[j]);
                if (dict.count(cur_wd) > 0) {
                    intervals.push_back({i, j});
                }
            }
        }

        sort(intervals.begin(), intervals.end());

        vector<Interval> merged;
        for (auto iv : intervals) {
            if (merged.empty() || iv.first > merged.back().second + 1) {
                merged.push_back(iv);
            } else {
                merged.back().second = max(merged.back().second, iv.second);
            }
        }

        if (merged.empty()) { return s; }
        else {
            stringstream ss;
            ss << s.substr(0, merged[0].first);
            for (int i = 0; i < merged.size(); i++) {
                string wd = s.substr(merged[i].first, merged[i].second + 1 - merged[i].first);
                ss << "<b>" << wd << "</b>";

                string next_not_included;
                if (i == merged.size()-1) {
                    next_not_included = s.substr(merged.back().second + 1);
                } else {
                    next_not_included = s.substr(
                            merged[i].second + 1, merged[i+1].first - merged[i].second - 1);
                }
                ss << next_not_included;

            }
            return ss.str();
        }
    }
};

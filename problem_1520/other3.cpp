/*
First find all the possible substrings. There will be at most one for each letter in s.
If we start at the first occurence of each letter and keep expanding the range
to cover all occurences, we'll find all the substrings in O(26 * n) time.

Once we've found all the possible substrings, this is a standard problem:
interval scheduling maximization problem (ISMP) (https://en.wikipedia.org/wiki/Interval_scheduling)

We can solve this in O(n) time by greedily taking the next non-overlapping substring with the left-most endpoint.
*/
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        
        vector<int> fst(26, INT_MAX);
        vector<int> lst(26, INT_MIN);
        for (int i = 0; i < n; i++) {
            fst[s[i] - 'a'] = min(fst[s[i] - 'a'], i);
            lst[s[i] - 'a'] = max(lst[s[i] - 'a'], i);
        }
        
        vector<pair<int, int>> t;
        for (int i = 0; i < 26; i++) {
            if (fst[i] < n) {
                int b = fst[i];
                int e = lst[i];
                for (int j = b; j <= e; j++) {
                    b = min(b, fst[s[j] - 'a']);
                    e = max(e, lst[s[j] - 'a']);
                }
                if (b == fst[i]) {
                    t.emplace_back(e, b);
                }
            }
        }
        
        sort(t.begin(), t.end());
        vector<string> ans;
        int prev = -1;
        for (auto &[e, b] : t) {
            if (b > prev) {
                ans.push_back(s.substr(b, e - b + 1));
                prev = e;
            }
        }
        
        return ans;
    }
};

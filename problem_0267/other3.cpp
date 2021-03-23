class Solution {
public:
    vector<string> res;
    void backtrack(int n, string temp, unordered_map<char,int>& count) {
        if(temp.length() == n) {
            res.push_back(temp);
            return;
        }
        for(auto it = count.begin(); it != count.end(); it++) {
            char c = it->first;
            if(count[c] == 0) continue;
            string temp1 = c + temp + c;
            count[c] -= 2;
            backtrack(n, temp1, count);
            count[c] += 2;
        }
    }
    vector<string> generatePalindromes(string s) {
        int n = s.length();
        unordered_map<char,int> count;
        for(char c:s) count[c]++;
        int c_odd = 0;
        char c_ind;
        for(auto it = count.begin(); it != count.end(); it++) {
            char c = it->first;
            int cnt = it->second;
            if(cnt&1) {
                c_ind = c;
                c_odd++;
            }
        }
        string temp = "";
        if(n & 1) {
            if(c_odd != 1) return {};
            temp = c_ind;
            count[c_ind]--;
        } else {
            if(c_odd != 0) return {};
        }
        backtrack(n, temp, count);
        return res;
    }
};

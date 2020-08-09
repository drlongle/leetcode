class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < n;i++){
            int x = t[i] - s[i];
            if(x < 0) x = 26 + x;   // s[i] > t[i] then we have to roll back
            if(x != 0) {
                int cnt = mp[x]*26 + x;    //if same x comes then we can roll for another 26 times if we have moves
                if(cnt > k) return false;  // if moves are more then limit then return false
            }
            mp[x]++;
        }

        return true;
    }
};

// just calulate the number of the characters need to be change for each string

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int l = 0,r = s.size(), a = 0,b = t.size();
        while(l < r && a < b && s[l] == t[a] ){
            l++;
            a++;
        }
        while( l < r && a < b && s[r-1] == t[b-1] ){
            r--;
            b--;
        }
        return r-l+ b-a ==1 || r-l == 1 && b-a == 1;
    }
};

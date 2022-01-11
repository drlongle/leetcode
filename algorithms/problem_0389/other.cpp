class Solution {
public:
    char findTheDifference(string s, string t) {
        int xorred = 0;
        for(auto ch: t) xorred ^= ch;
        for(auto ch: s) xorred ^= ch;
        return (xorred);
    }
};


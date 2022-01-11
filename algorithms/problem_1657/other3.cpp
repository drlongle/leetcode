class Solution {
public:
    bool closeStrings(const string& word1, const string& word2) {
        if(word1.length()!=word2.length())
            return false;
        set<char> s1,s2;
        vector<int> freq1(26,0),freq2(26,0);

        for(char c: word1) {
            s1.insert(c);
            freq1[c-'a']++;
        }
        for(char c: word2) {
            s2.insert(c);
            freq2[c-'a']++;
        }

        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));

        return s1==s2 && freq1==freq2;
    }
};

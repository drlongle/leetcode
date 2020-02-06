// KMP

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string pattern = first + " " + second + " "; 
        vector<int> pmt(text.size(), 0);
        // O(M)
        for(int i = 1, length = 0; i < text.size(); ) {
            if(pmt[i] == pmt[length]) pmt[i++] = ++length;
            else if(length == 0) pmt[i++] = 0;
            else length = pmt[length-1];
        }
        vector<string> cache;
        int i = 0, j = 0;
        // O(N)
        while(i < text.size()) {
            if(text[i] == pattern[j]) {
                if(j == 0 && !(i == 0 || text[i-1] == ' ')) {
                    i++; continue; // for text:  aa good girl,  pattern:a good girl
                }
                ++i; ++j;
                if(j == pattern.size()) {
                    j = 0;
                    int start = i, end = i;
                    while(end < text.size() && text[end] != ' ') ++end;
                    cache.push_back(text.substr(start, end-start));
                }
            }
            else if(j == 0) ++i;
            else j = pmt[j-1];
        }
        return cache;
    }
};

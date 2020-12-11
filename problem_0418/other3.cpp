class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s = "";
        for(string c : sentence) {
            s += " " + c;
        }
        int st = 1;
        for(int r = 0;r<rows;r++,st++) {
            st += cols;
            while(s[st % s.length()] != ' ')st--;
        }
        return (--st)/s.length();
    }
};

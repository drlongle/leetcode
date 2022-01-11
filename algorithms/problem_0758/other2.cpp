class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int size = S.size();
        vector<bool> bolded(size, false);
        for(const auto &w: words) {
            int len = w.size();
            size_t next = S.find(w, 0);
            while(next != string::npos) {
                for(int i = 0; i < len; ++i)
                    bolded[i+next] = true;
                next = S.find(w, next+1);
            }
        }
        string res = "";
        bool bold = false;
        for(int i = 0; i < size; ++i) {
            if(bolded[i]) {
                if(!bold) bold = true, res += "<b>";
            } else {
                if(bold) bold = false, res += "</b>";
            }
            res += S[i];
        }
        if(bold) res += "</b>";
        return res;
    }
};

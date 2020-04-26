class Solution {
public:
    string reformat(string s) {
        string alpha, digit;
        for (char c: s)
            if (isalpha(c))
                alpha.push_back(c);
            else
                digit.push_back(c);
        
        if (abs<int>(alpha.size() - digit.size()) > 1)
            return "";
        
        string& larger = alpha.size() > digit.size() ? alpha : digit;
        string& smaller = alpha.size() > digit.size() ? digit : alpha;
        
        string res(larger.size() + smaller.size(), ' ');
        for (int i = 0, j = 0; j < larger.size(); i += 2, j++)
            res[i] = larger[j];
        for (int i = 1, j = 0; j < smaller.size(); i += 2, j++)
            res[i] = smaller[j];
        
        return res;
    }
};

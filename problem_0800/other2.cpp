class Solution {
public:
    string helper(string s) {
        int q = stoi(s,nullptr,16)/17;
        int r = stoi(s,nullptr,16)%17;
        if (r > 8)
            ++q;

        string res = "00";

        if (q < 10) {
            res[0] = char('0'+q);
            res[1] = char('0'+q);
        }
        else {
            res[0] = char('a'+q-10);
            res[1] = char('a'+q-10);
        }

        return res;
    }

    string similarRGB(string color) {
        string res = "#";

        for (int i = 1; i < 6; i += 2)
            res += helper(color.substr(i,2));

        return res;
    }
};

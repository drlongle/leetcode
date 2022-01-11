class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        for (int i = 2; i < S.size() - 1; i++) {
            string strs[2] = {S.substr(1,i-1), S.substr(i,S.size()-i-1)};
            xPoss.clear();
            for (int j = 0; j < 2; j++)
                if (xPoss.size() || !j) parse(strs[j], j);
        }
        return ans;
    }
private:
    vector<string> ans, xPoss;
    void parse(string str, int xy) {
        if (str.size() == 1 || str.front() != '0')
            process(str, xy);
        if (str.size() > 1 && str.back() != '0')
            process(str.substr(0,1) + "." + str.substr(1), xy);
        if (str.size() > 2 && str.front() != '0' && str.back() != '0')
            for (int i = 2; i < str.size(); i++)
                process(str.substr(0,i) + "." + str.substr(i), xy);
    }
    void process(string str, int xy) {
        if (xy)
            for (auto x : xPoss)
                ans.push_back("(" + x + ", " + str + ")");
        else xPoss.push_back(str);
    }
};

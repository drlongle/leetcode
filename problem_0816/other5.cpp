class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        string a = s.substr(1,1), b = s.substr(2);
        b.pop_back();
        while(!b.empty()) {
            vector<string> left = getStrDots(a);
            vector<string> right = getStrDots(b);
            for(string lstr : left) {
                for(string rstr: right) res.push_back("("+lstr+", "+rstr+")");
            }
            a.push_back(b.front());
            b.erase(0,1);
        }
        return res;
    }

    //generating all valid cordinates of givens str
    vector<string> getStrDots(string &str) {
        vector<string> res;
        if(isValidStr(str)) res.emplace_back(str);
        for(int i = 1; i < str.size(); i++) {
            string temp = str.substr(0, i) + "." + str.substr(i);
            if(isValidStr(temp)) res.emplace_back(temp);
        }
        return res;
    }


    bool isValidStr(string &str) {
        // handle case of .12, 123., .0
        if(str.size() > 0 && (str[0] == '.' || str.back() == '.')) return false;
        //handle case of 12.0, 123.00, 0.0
        if(str.size() > 1 && str.find(".") != string::npos && str.back() == '0') return false;
        // handle case of 01, 001, 0123
        if(str.size() > 1 && str[0] == '0' && str[1] != '.') return false;
        return true;
    }
};

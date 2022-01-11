class Solution {
public:
    string reformatDate(string date) {
        std::stringstream ss{date};
        std::string d, m, y, dd{"0"};
        ss >> d >> m >> y;
        if(d.size() == 3) dd += d[0];
        else dd = d.substr(0,2);
        return y+"-"+mm[m]+"-"+dd;
    }
    
    std::unordered_map<std::string, std::string> mm{{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};    
};

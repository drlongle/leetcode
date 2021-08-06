class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> digits ;
        for (int i=0; i<time.size(); i++) {
            if (i==2) continue ;
            digits.push_back(time[i]) ;
        }
        vector<char> limits = {'2', '9', '9', '5', '9'} ;
        if (time[0]=='2') limits[1] = '4' ;

        sort(digits.begin(), digits.end()) ;

        for (int ix=time.size()-1; ix>=0; ix--) {
            if (ix==2) continue ;
            for (auto d:digits) {
                if (d>time[ix] && d<=limits[ix]) {
                    time[ix] = d ;
                    return time ;
                }
            }
            time[ix] = digits[0] ; // assign the smallest
        }
        return time ;
    }
};

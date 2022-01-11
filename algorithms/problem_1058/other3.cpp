class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int sumFloor=0, sumCeil=0;
        multimap<double,double> m; // (x-floor),  x
        for(auto p:prices){
            double x = stod(p);
            sumFloor += floor(x);
            sumCeil += ceil(x);
            m.emplace(x - floor(x), x);
        }
        if(sumFloor > target || sumCeil < target) return "-1";
        int numFloor = prices.size() - (target - sumFloor);
        double sumError = 0;
        int count = 0;
        for(auto [delta, x] : m)
            sumError += count++ < numFloor ? x - floor(x) : ceil(x) - x;

        auto s = to_string (sumError);
        return s.substr(0, s.find_first_of ('.', 0) + 4);
    }
};

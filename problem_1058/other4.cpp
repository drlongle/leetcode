/*
Try to use ceil for each price, we can then find a maximum target
Try also to use floor for each price, we can get a minimum target
If the parameter is not within such [minimum, maximum] range, return "-1"
If target is within the range of [minimum, maximum] range, we can find out the number of round_ups by target - _min.
Sort the prices array by ascending order of round errors, smaller errors for round up come first.
The only corner case is when there is no round up error, we need to skip such element
*/

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int _max{}, _min{}, c{};
        double err{};
        vector<double> dprices;
        for (auto& p : prices){
            dprices.push_back (stod(p));
            _max += static_cast<int> (ceil (dprices.back()) );
            _min += static_cast<int> (floor (dprices.back()) );
        }
        if ( target < _min || target > _max) return "-1";
        int round_ups = target - _min;
        sort (dprices.begin(), dprices.end(), [] (double d1, double d2){
            return  ceil (d1) - d1< ceil (d2) - d2;
        });
        for (int i = 0; i < dprices.size(); ++ i) {
            if (c < round_ups && ceil (dprices[i]) - dprices[i] != 0) {
                err += (ceil (dprices[i]) - dprices[i]);
                c++;
            }
            else if (c >= round_ups) err += (dprices[i] - floor (dprices[i]) );
        }
        string s = to_string (err);
        return s.substr (0, s.find_first_of ('.', 0) + 4);
    }
};

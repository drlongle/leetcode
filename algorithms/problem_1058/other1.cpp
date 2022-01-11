// Find out how many "ceiling" roundings we need to hit the target, and perform them on
// the elements with the largest fractional component

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        vector<double> nums(prices.size(), 0);
        vector<int> ceils(prices.size(), 0);
        vector<int> floors(prices.size(), 0);
        std::transform(prices.begin(), prices.end(), nums.begin(), [](string price) { return std::stod(price); });
        std::transform(nums.begin(), nums.end(), floors.begin(), [](double price) { return std::floor(price); });
        std::transform(nums.begin(), nums.end(), ceils.begin(), [](double price) { return std::ceil(price); });
        int lower_bound = std::accumulate(floors.begin(), floors.end(), 0, std::plus{});
        int upper_bound = std::accumulate(ceils.begin(), ceils.end(), 0, std::plus{});

        if (lower_bound > target)
            return "-1";
        if (upper_bound < target)
            return "-1";

        // turns all numbers from XX.YYY into 0.YYY (errors from floor)
        std::transform(nums.begin(), nums.end(), nums.begin(), [](double price) { return price - ((int) price); });
        // sort high to low: 0.999 - 0.000
        std::sort(nums.begin(), nums.end(), std::greater<>{});
        // turn #num_ceils floor errors into ceiling error
        int num_ceils = target - lower_bound;
        std::transform(nums.begin(), nums.begin()+num_ceils, nums.begin(), [](double floor_error) { return 1-floor_error; });
        // sum errors
        double error = std::accumulate(nums.begin(), nums.end(), 0.0, std::plus{});
        // output
        stringstream ss;
        ss << std::fixed << std::setprecision(3) << error;
        return ss.str();
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        deque<string> strs;
        for (int n: nums)
            strs.emplace_back(to_string(n));
        auto lambda = [] (string& a, string &b) {
            return a + b > b + a;
        };
        sort(begin(strs), end(strs), lambda);
        while (strs.size() > 1 && strs.front() == "0")
            strs.pop_front();
        ostringstream oss;
        for (auto& s: strs)
            oss << s;
        return oss.str();
    }
};

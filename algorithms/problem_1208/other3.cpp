class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
	vector<int> prefix(1); // cost up to this point
	int best = 0, cost = 0;
	for (int i=0; i<s.size(); ++i) {
            cost += abs(s[i]-t[i]);
            prefix.push_back(cost);

            // find last number that does not fit within maxCost (binary search)
            const auto it = upper_bound(prefix.begin(), prefix.end(), cost-maxCost-1);
            best = max(best, int(prefix.end()-it-1)); // best substring begins from the next element
	}
	return best;
    }
};

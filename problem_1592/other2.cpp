class Solution {
public:
    using Words = vector<string>;
    string reorderSpaces(string s, string word = {}, Words A = {}) {
        int K = count(s.begin(), s.end(), ' ');
        for (istringstream is{ s }; is >> word; A.emplace_back(word));
        int N = A.size();
        if (N == 1)
            return A[0] + string(K, ' ');
        auto space = K / (N - 1), leftover = K % (N - 1);
        ostringstream os; for (auto& word: A) os << word << string(space, ' ');
        auto ans = os.str();
        while (ans.back() == ' ') ans.pop_back();  // pop space intended for "in between" words (which is appended onto the end, since we need boost to join in C++)
        return ans + string(leftover, ' ');
    }
};

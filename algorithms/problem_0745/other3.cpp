class WordFilter {
public:
    WordFilter(vector<string>& words) : words_(words) {
        for (int k = 0; k < size(words); ++k) {
            const auto& word = words[k];
            const int n = size(word);
            for (int i = 0; i < n; ++i) {
                prefix_to_idxs[string_view(word.data(), i + 1)].push_back(k);
                suffix_to_idxs[string_view(word.data() + i, n - i)].push_back(k);
            }
        }
    }

    int f(string prefix, string suffix) {
        const auto it = prefix_to_idxs.find(prefix);
        const auto it_suffix = suffix_to_idxs.find(suffix);
        if (it == cend(prefix_to_idxs) || it_suffix == cend(suffix_to_idxs)) {
            return -1;
        }

        const auto& suffix_idxs = it_suffix->second;
        const auto& prefix_idxs = it->second;
        for (int i = size(prefix_idxs) - 1; i >=0; --i) {
            if (binary_search(cbegin(suffix_idxs), cend(suffix_idxs), prefix_idxs[i])) {
                return prefix_idxs[i];
            }
        }
        return -1;
    }

    unordered_map<string_view, vector<int>> prefix_to_idxs;
    unordered_map<string_view, vector<int>> suffix_to_idxs;
    vector<string> words_;
};

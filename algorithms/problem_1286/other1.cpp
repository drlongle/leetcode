class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) : selected(), chars(characters), len(combinationLength), idxs(26, 0) {
        selected = chars.substr(0, len);
        for (size_t i = 0; i < chars.length(); i++) idxs[chars[i] - 'a'] = i;
    }
    
    string next() {
        string res = selected;
        while (selected.length()) {
            size_t idx = idxs[selected.back() - 'a'];
            selected.pop_back();
            if (chars.length() - idx > len - selected.length())  {
                selected += chars.substr(idx + 1, len - selected.size());
                break;
            }
        }
        return res;
    }
    
    bool hasNext() {
        return selected.length();
    }
protected:
    string selected;
    string chars;
    size_t len;
    vector<size_t> idxs;
};

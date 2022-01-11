class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for(string& s : strs) {
            result += s;
            result.push_back(0);
        }

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        auto begin = s.begin();
        auto end = find(s.begin(), s.end(), 0);
        while(end != s.end()) {
            result.emplace_back(begin, end);
            begin = next(end);
            end = find(begin, s.end(), 0);
        }

        return result;
    }
};

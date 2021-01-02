class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto& str : strs) {
            int sz = str.size();
            res.append(reinterpret_cast<char*>(&sz), sizeof(int));
            res.append(str);
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        size_t pos = 0;
        while (pos < s.size()) {
            int sz;
            memcpy(&sz, &s[pos], sizeof(int));
            pos += sizeof(int);
            res.emplace_back(s.substr(pos, sz));
            pos += sz;
        }
        return res;
    }
};

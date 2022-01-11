const unordered_map<string, string> m = {
    {"&quot;", "\""}, {"&apos;", "\'"}, {"&amp;", "&"}, {"&gt;", ">"}, {"&lt;", "<"}, {"&frasl;", "/"}
};

class Solution {
public:
    string entityParser(string text) {
        for (auto&& [key, val]: m) {
            regex e(key);
            text = regex_replace(text, e, val);
        }
        return text;
    }
};

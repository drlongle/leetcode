class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        string part;
        vector<string> parts;
        while (getline(iss, part, '/')) {
            if (part == ".")
                continue;
            if (part == "..") {
                if (parts.size() > 0) {
                    parts.pop_back();
                }
            } else if (part.size())
                parts.emplace_back(part);
        }
        ostringstream oss;
        oss << "/";
        for (int i = 0, n = parts.size(); i < n; ++i) {
            oss << parts[i];
            if (parts[i] != "/" && i < n - 1)
                oss << "/";
        }
        return oss.str();
    }
};

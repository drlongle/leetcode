class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k)
    {
        unordered_map<string_view, string_view> um;
        for(const auto & i : k) um[string_view(i[0].c_str(), size(i[0]))] = string_view(i[1].c_str());

        string out;
        for(auto i{0}; i<size(s); ++i)
            if(s[i]=='(')
            {
                auto j = distance(begin(s), find(begin(s)+i, end(s), ')'));
                string_view sv(s.c_str()+i+1, j-i-1);
                out += um.find(sv)!=end(um) ? um[sv] : "?"s;
                i=j;
            }
            else
                out.push_back(s[i]);
        return move(out);
    }
};

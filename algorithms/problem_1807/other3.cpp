class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string answer;
        unordered_map<string,string> mp;

        for(auto& i : knowledge) mp[i[0]] = i[1];

        for(int i = 0; i != s.size(); i++)
            if(s[i] != '(') answer.push_back(s[i]);
            else {
                string tmp = "";
                while(s[++i] != ')') tmp.push_back(s[i]);

                if(mp.count(tmp)) answer += mp[tmp];
                else answer.push_back('?');
            }

        return answer;
    }
};

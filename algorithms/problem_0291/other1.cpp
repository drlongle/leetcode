class Solution {
public:
    bool ans = false;

    bool check(string pat,string s,vector<string>& vec)
    {
        string curr="";
        for(auto ch : pat)
            curr+=vec[ch-'a'];
        return curr==s;
    }

    void backtrack(string s, string pat, unordered_set<string>& vis,
                   vector<string>& vec, vector<char>& t, int start, int ind)
    {
        if(ind==t.size())
        {
            ans = check(pat,s,vec);
            return;
        }
        string curr="";

        for(int i=1;i<=(s.size()-start) and !ans;i++)
        {
            curr=s.substr(start,i);
            if(vis.insert(curr).second)
            {
                vec[t[ind]-'a'] = curr;
                backtrack(s,pat,vis,vec,t,start+i,ind+1);
                vis.erase(curr);
            }
        }
    }

    bool wordPatternMatch(string pat, string s) {
        vector<string> vec(26,"");
        vector<char> t;
        unordered_set<string> vis;
        for(auto ch : pat)
        {
            if(vec[ch-'a'].empty())
            {
                t.push_back(ch);
                vec[ch-'a']+=ch;
            }
        }

        backtrack(s,pat,vis,vec,t,0,0);

        return ans;
    }
};

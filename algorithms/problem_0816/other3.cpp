class Solution {
public:
    vector<string> possible(string s)
    {
        int n = s.length();
        vector<string> store;

        if(n==1){
            store.push_back(s);
            return store;
        }
        if(s[0]=='0' and s[n-1]=='0')
            return store;
        if(s[0]=='0'){
            store.push_back("0."+s.substr(1));
            return store;
        }
        if(s[n-1]=='0'){
            store.push_back(s);
            return store;
        }

        // put '.' in between the digits
        string rev = s;
        string start = "";
        store.push_back(s);

        for(int i=0;i<n-1;i++){
            start+=s[i];
            rev.erase(rev.begin());
            store.push_back(start+'.'+rev);
        }

        return store;
    }

    vector<string> ambiguousCoordinates(string s)
    {
        int n = s.length();
        vector<string> ans;
        for (int i = 1; i < n - 2; i++){
            vector<string> A = possible(s.substr(1,i));
            vector<string> B = possible(s.substr(i+1,n-i-2));
            for (auto &ch1 : A)
                for (auto &ch2 : B)
                    ans.push_back("(" + ch1 + ", " + ch2 + ")");
        }
        return ans;
    }
};

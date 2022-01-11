class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        vector<string>tmp;
        for(auto str:strs)
        {
            string clone = str;
            reverse(clone.begin(),clone.end());
            if(str.compare(clone)>0)
                tmp.push_back(str);
            else
                tmp.push_back(clone);
        }
        string res;
        for(int i = 0;i<tmp.size();i++)
        {
            string str = tmp[i];
            string rev = tmp[i];
            reverse(rev.begin(),rev.end());
            vector<string> candidates = {str,rev};
            for(auto candidate:candidates)
            {
                for(int k = 0;k<candidate.size();k++)
                {
                    string t = candidate.substr(k);
                    for (int j = i + 1; j < tmp.size(); j++)t+=tmp[j];
                    for (int j = 0; j < i; j++)t+=tmp[j];
                    t+=candidate.substr(0,k);
                    if (t.compare(res) > 0)
                        res = t;
                }
            }
        }
        return res;
    }
};

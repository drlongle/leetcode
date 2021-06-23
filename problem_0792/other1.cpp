class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int count =0;

        unordered_map< string, int>mp;
        for (int i = 0; i < words.size(); i++)
            mp[words[i]]++;

        for(auto x: mp){
            int i =0;
            int j = 0;

            while(i< n && j< x.first.size()){
                if(s[i]==x.first[j]){
                    j++;
                }

                i++;
            }

            if(j==x.first.size())
                count = count + x.second;
        }

        return count;
    }
};
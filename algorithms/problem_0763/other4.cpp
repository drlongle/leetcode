class Solution {
public:
    vector<int> partitionLabels(string S) {
        int cnt[26]={0};
        for(char ch:S)
            cnt[ch-'a']++;
        int count=0,i=0,j=-1;
        unordered_set<char> set;
        vector<int> ans;
        for(int i=0;i<S.size();i++)
        {
            if(set.find(S[i])!=set.end())
                count--;
            else
            {
                count+=(cnt[S[i]-'a']-1);
                set.insert(S[i]);
            }
            if(count==0)
            {
                ans.push_back(i-j);
                j=i;
            }
        }
        return ans;
    }
};


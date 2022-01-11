class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool>v(26,0);
        for(auto a:allowed)v[a-'a']=1;

        int count=0;
        for(auto a: words)
        {
            bool f=0;
            for(auto x:a)
            {
                if(v[x-'a']==0)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)count++;
        }
        return count;
    }
};

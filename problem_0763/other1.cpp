class Solution {
public:
    vector<int> partitionLabels(string s) {
        int a[30]={0};
        vector<int> v;
        for(int i=0;i<s.length();i++)
        {
            a[s[i]-'a']=i;
        }
        int i=0,j=a[s[0]-'a'];
        int m;
        while(i<s.length())
        {
            m=0;
            for(int k=i;k<=j;k++)
            {
                m=max(a[s[k]-'a'],m);
                if(m>j)
                    j=m;
            }
            v.push_back(m-i+1);
            i=m+1;
            if(i<s.length())
            j=a[s[i]-'a'];
        }
        return v;
    } 
};

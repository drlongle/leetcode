class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mp[120]={0};
        int ma=0,c=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            if(mp[tasks[i]]>ma){
                ma=mp[tasks[i]];
                c=1;
            }
            else if(mp[tasks[i]]==ma)
                c++;
        }
        int ans=0;
        ans=c+(ma-1)*(n+1);
        int z=tasks.size();
        ans=max(ans,z);
        return ans;
    }
};

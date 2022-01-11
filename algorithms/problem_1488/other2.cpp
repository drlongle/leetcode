class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int> s;
        set<int> store;
        int n=rains.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(rains[i]>0){
                if(s.count(rains[i])){
                    auto pos=store.upper_bound(s[rains[i]]);
                    if(pos==store.end())
                        return {};
                    else {
                        int ind=*pos;
                        store.erase(pos);
                        ans[ind]=rains[i];
                    }
                }
            } else 
                store.insert(i);
            
            s[rains[i]]=i;
        }
        for(int i:store)
            ans[i]=1;
        
        return ans;
    }
};

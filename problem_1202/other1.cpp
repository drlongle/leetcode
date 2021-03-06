class dsu{
public:
    vector<int> arr;
    dsu(int n):arr(n){
        for(int i=0;i<n;i++){
            arr[i]=i;
        }
    }
    int find(int a){
        if(arr[a]!=a){
            arr[a]=find(arr[a]);
        }
        return arr[a];
    }
    void merge(int a, int b){
        int x=find(a);
        int y=find(b);
        arr[x]=y;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        dsu DSU(n);
        for(auto v:pairs){
            DSU.merge(v[0],v[1]);
        }
        unordered_map<int,vector<char>> m;
        for(int i=0;i<n;i++){
            m[DSU.find(i)].push_back(s[i]);
        }
        for(auto &v:m){
            sort(v.second.rbegin(),v.second.rend());
        }
        string ans;
        for(int i=0;i<n;i++){
            int cur = DSU.find(i);
            ans.push_back(m[cur].back());
            m[cur].pop_back();
        }
        return ans; 
    }
};

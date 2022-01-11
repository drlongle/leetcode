class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& v) {
        vector<int> res;
        vector<vector<int>> map;
        for(int i=0;i<n+1;++i){
            vector<int>tmp;
            map.push_back(tmp);
        }
        for(auto i:v){
            map[i[0]].push_back(i[1]);
            map[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;++i){
            int f=1;
            bool tmp[]={false,false,false,false};
            for(int j:map[i+1]){
                if(j<=res.size())
                    tmp[res[j-1]-1]=true;
            }
            for(int j=0;j<4;++j){
                if(!tmp[j]){
                    f=j+1;
                    break;
                }
            }
            res.push_back(f);
        }
        return res;
    }
};

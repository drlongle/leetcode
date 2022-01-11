class Solution {
public:
    struct Node{
        int parent;
        int rank ;
    };
    vector<Node> v;
    int ans;
    int find(int i){
        if(v[i].parent==-1){
            return i;
        }
        return v[i].parent = find(v[i].parent);
    }

    void un(int fromp, int top){
        if(v[fromp].rank>v[top].rank){
            v[top].parent = fromp;
        }
        else if(v[fromp].rank<v[top].rank){
            v[fromp].parent = top;
        }
        else{
            v[fromp].parent = top;
            v[top].rank+=1;
        }
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        v.resize(n);
        for(int i=0; i<n; i++){
            v[i].parent = -1;
            v[i].rank = 0;
        }
        for(auto p:logs){
            int fromp = find(p[1]);
            int top = find(p[2]);
            if(fromp==top){
                continue;
            }
            else{
                ans = p[0];
            }
            un(fromp,top);
        }
        int abs_parent = find(0);
        for(int j=0; j<n;j++){

            if(find(j)!= abs_parent){
                return -1;
            }
        }
        return ans;
    }
};

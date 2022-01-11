
const int nax = 1e5 + 5;

class Solution {
public:
    int parent[nax];
    int sz[nax];

    void Set(int i){
        sz[i] = 1, parent[i] = i;
    }

    int find(int a){
        if(a == parent[a]) return parent[a];
        return parent[a] = find(parent[a]);
    }

    void merge(int a, int b){
        a = find(a), b = find(b);
        if(a != b) {
            if(sz[a] < sz[b]){
                sz[b] += sz[a];
                parent[a] = b;
            }
            else{
                sz[a] += sz[b];
                parent[b] = a;
            }
        }
        return;
    }
    int largestComponentSize(vector<int>& A) {
        if(A.size() == 0) return 0;
        for(auto it : A) Set(it);
        int cnt[nax];
        memset(cnt, 0, sizeof cnt);
        for(auto it : A) cnt[it] = 1;
        int n = A.size();
        for(int g = 2; g < nax; g++){
            int group, counter = 0;
            for(int j = g; j < nax; j += g){
                if(cnt[j] && !counter){
                    group = j; counter = 1;
                    break;
                }
            }
            if(counter){
                for(int j = g; j < nax; j += g) if(cnt[j]) merge(j, group);
            }
        }
        int ans = 1;
        int sz[nax] = {0};
        for(auto it : A){
            int g = find(it);
            sz[g]++;
            ans = max(ans, sz[g]);
        }
        return ans;
    }
};

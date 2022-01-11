class Solution {
public:
    int n;
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        n = org.size();
        vector<set<int>> graph(n+1);
        vector<bool> appearInSeq(n+1,false);
        for(auto seq:seqs){
            for(int i=0;i<seq.size();i++){
                int x=seq[i];
                // check if illegal entry
                if(x<1 || x>n) return false;
                appearInSeq[x]=true;
                if(i) graph[seq[i-1]].insert(x);
            }
        }
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
            int x=org[i];
            // check if appeared at least once in seqs
            if(!appearInSeq[x]) return false;
            // check if unique topological sort equivalent to org possible
            if(i && graph[org[i-1]].find(x) == graph[org[i-1]].end())
                return false;
            // check for cycles
            vis[x]=true;
            for(auto child: graph[x])
                if(vis[child])
                    return false;
        }
        return true;
    }
};

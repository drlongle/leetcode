class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> indeg(n+1, 0);
        unordered_map<int, vector<int> > mp;
        //--- range check to ensure graph node is given within range of 1-n
        for(auto& row:seqs){
            for(int i=0; i<row.size(); i++){
                if(row.at(i)<1 || n<row.at(i)) return false;
            }
        }
        //--- contruct graph
        for(auto& row:seqs){
            for(int i=1; i<row.size(); i++){
                mp[row.at(i-1)].push_back(row.at(i));
                indeg.at(row.at(i))++;
            }
        }
        //--- just to handle corner case where graph is empty
        if(mp.empty()) {
            for(auto& row:seqs) if(row.at(0)==org.at(0)) return true;
            return false;
        }

        //--- normal topological sort
        queue<int> que;
        for(int i=1; i<indeg.size(); i++){
            if(indeg.at(i)==0) que.push(i);
        }

        int id=0;   //--- pointer in "org"
        while(!que.empty()){
            if(que.size()>1) return false;     //--- reject the case where we have multiple candidate of reconstructing sequence

            int cur = que.front(); que.pop();
            if(org.at(id)!=cur) return false;   //--- reject when reconstructed sequence does not match "org"
            id++;

            for(int next:mp[cur]){
                if(--indeg.at(next)==0) que.push(next);
            }
        }

        return id==org.size();     //--- ensure if the pointer goes to the end of "org"
    }
};


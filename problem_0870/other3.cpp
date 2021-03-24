class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(),A.end());
        vector<int> C;
        C=B;
        sort(B.begin(),B.end());
        vector<int> ans;
        map<int,vector<int>> w;
        int count=0;
        int i=0;
        int j=0;
        int k=B.size()-1;
        while(j<B.size() && i<A.size()){
            if(A[i]>B[j]){
                count+=1;
                w[B[j]].push_back(A[i]);
                i+=1;
                j+=1;
            }
            else{
                w[B[k]].push_back(A[i]);
                i+=1;
                k-=1;

            }

        }

        for(auto i:C){
            ans.push_back(w[i][w[i].size()-1]);
            w[i].pop_back();
        }

        return ans;
    }
};

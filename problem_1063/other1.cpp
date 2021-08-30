class Solution {
public:
    int validSubarrays(vector<int>& A) {
        int res=0;
        vector<int>sta;
        for(int i=0;i<A.size();i++){
            res++;
            while(sta.size()>0&&A[i]<sta[sta.size()-1])sta.pop_back();
            res+=sta.size();
            sta.push_back(A[i]);
        }
        return res;
    }
};

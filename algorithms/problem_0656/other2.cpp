/*
 * The idea is to maintain min cost to reach end from the right end of the input in a separate array.
 * Keep the cost to reach end from the last B locations in a list and use this list to estimate
 * the minimum cost to reach from the current location.
 */

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        vector<int> ary(A.size(),0);
        list<int> l1;
        for(int i=A.size()-1;i>=0;i--){
            if(l1.size() && A[i]!=-1){
                if(ary[l1.front()]==INT_MAX)
                    ary[i] = INT_MAX;
                else
                    ary[i]=ary[l1.front()]+A[i];
            }else{
                if(A[i]==-1)
                    ary[i] = INT_MAX;
                else
                    ary[i] = A[i];
            }
            if(l1.size() && l1.front()==i+B )l1.pop_front();
            while(l1.size() && ary[l1.back()]>ary[i]){
                l1.pop_back();
            }
            l1.push_back(i);
        }
        vector<int> res;int pidx;
        for(int i=0;i<ary.size();i++){
            if(ary[0]==INT_MAX) break;
            if(ary[i]==INT_MAX) continue;
            if(i==0 || ary[pidx] - A[pidx] == ary[i]){
                pidx = i;
                res.push_back(i+1);
            }
        }
        return res;
    }
};
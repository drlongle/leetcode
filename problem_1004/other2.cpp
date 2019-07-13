class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        /*
         * use 2 pointers l, r for the sub array
         * use queue to record zero indexes and move l after it 
         * meanwhile change counter
         */
        int c = K;//counter
        int l = 0, r = 0;
        queue<int> z;//record zero indexes
        int max_len = K;//at least K can be 1s
        while(r < A.size()) {
            if(A[r] == 0) {
                z.push(r);
                ++r;
                if(c > 0)
                {
                    --c;
                }
                else{
                    max_len = max(r-l-1, max_len);
                    l = z.front() + 1;
                    z.pop();
                }
            }
            else{
                ++r;
            }
        }
        max_len = max(r-l, max_len);
        return max_len;
    }
};


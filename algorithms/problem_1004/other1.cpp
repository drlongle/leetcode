class Solution {
    int longestOnes(vector<int>& A, int K) {
        int start = 0;
        int count = 0;
        int res = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] == 0) count++;
            while(count > K)
            {
                while(start <= i and A[start] == 1)
                    start++;
                count--;
                start++;
            }
            res = max(res, i-start+1);
        }
        return res;
    }
};

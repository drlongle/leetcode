class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size() <= 0)
            return 0;

        //Get Max and Min from the A.
        int minN = INT_MAX;
        int maxN = INT_MIN;

        for(auto& a: A)
        {
            minN = min(a, minN);
            maxN = max(a, maxN);
        }

        //Difference of Max - Min by decreasing K from max and Adding K to min
        int diff = (maxN - K) -  (K + minN);

        return diff < 0 ? 0 : diff ;
    }
};


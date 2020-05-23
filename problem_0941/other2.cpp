class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int size = A.size();
        int state=0;
        
        if (size < 3) return false;
        
        for(int i=0; i<size-1; i++)
        {
            switch(state)
            {
                case 0:
                    if (A[i] >= A[i+1]) return false;
                    state=1;
                    break;
                case 1:
                    if (A[i] == A[i+1]) return false;
                    if (A[i] > A[i+1]) state=2;
                    break;
                case 2:
                    if (A[i] <= A[i+1]) return false;
            }
        }
        if(state < 2) return false;
        else          return true;
    }
};

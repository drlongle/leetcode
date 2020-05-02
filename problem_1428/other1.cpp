class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dims = binaryMatrix.dimensions();
        int N = dims[0], M = dims[1];
        int leftmost = M;
        for(int r = 0; r < N; r++) {
            int low = 0, high = M - 1;
            while( low <= high ) {
                int mid = low + (high-low)/2;
                int val = binaryMatrix.get(r,mid);
                if(val == 0)
                    low = mid + 1;
                else if(val == 1)
                    high = mid - 1;
            }
            leftmost = min(leftmost, low);
        }
        return leftmost == M ? -1 : leftmost;
    }
};

class Solution {
public:
    bool confusingNumber(int N) {
        int res = 0, NN = N;
        int log[] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        while(N) {
            int d = N % 10;
            res *= 10;
            if(log[d] == -1) return false;
            res += log[d];
            N /= 10;
        }

        return res != NN;
    }
};

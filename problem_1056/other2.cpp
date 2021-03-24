class Solution {
public:
    bool confusingNumber(int N) {
        unordered_map<int, int> rotate;
        rotate[6] = 9;
        rotate[9] = 6;
        rotate[0] = 0;
        rotate[1] = 1;
        rotate[8] = 8;

        int source = N;
        int res = 0;
        while (N > 0) {
            if (rotate[N % 10] == 0 && N % 10 != 0) return false;
            else res = res * 10 + rotate[N % 10];
            N = N/10;
        }
        return (res != source);
    }
};


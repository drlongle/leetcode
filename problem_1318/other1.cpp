class Solution {
public:
    int minFlips(int a, int b, int c) {

        int cnt = 0;
        int a1, b1, c1;
        
        while (a || b || c) {
            a1 = a%2;
            b1 = b%2;
            c1 = c%2;
            
            if (c1 == 0) cnt += (a1 + b1);
            else {
                if (a1 + b1 == 0) ++cnt;
            }
        
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return cnt;
   }
};

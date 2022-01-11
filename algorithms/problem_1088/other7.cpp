inline int get180 (int i) {
    return (i==0)? 0 :(i==1? 1: (i==6? 9: (i==9? 6: (i==8?8 : -1))));
}

class Solution {
public:
    int confusingNumberII(int N) {

        int cnt = 0;
        int i=1;

        while (i<=N) {

            int n=i;
            int ans=0;
            bool ignore = false;
            long jump = 1;
            int lastdigit;

            while(n!=0) {
                lastdigit = n%10;
                int inv = get180(lastdigit);
                if (inv==-1) {
                    ignore = true;
                    break;
                }
                ans = ans * 10 + inv;
                n = n/10;
                jump = jump*10;
            }

            if (ignore==false) {
                if (ans!=i) cnt++;
            } else {
                if (lastdigit == 7) i = i + (jump)-1;            // because 7 does not have a rotating counterpart
                else if (lastdigit == 2) i = i + 4 * jump-1;     // because 2, 3, 4, 5 do not have a rotating counterpart
            }

            i++;
        }

        return cnt;
    }
};

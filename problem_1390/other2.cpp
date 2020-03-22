class Solution {
public:
    int sumOfDivisors(int num){
        int res = 0;
        int count = 0;
        int sq = (int) sqrt(num);
        for (int i=1; i<=sq;i++ ) {
            if (num % i == 0) {
                count += 2;
                res += num/i;
                res += i;
                if (count > 4)
                    break;
            }
        }
    
        if (sq * sq == num) {
            count--;
            res -= sq;
        }
            
        if (count == 4)
            return res;
        return -1;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        int sumDiv;
        for (int num: nums) {
            sumDiv = sumOfDivisors(num);
            if ( sumDiv != -1) {
                res +=  sumDiv;               
            }
        }
        return res;
    }
};

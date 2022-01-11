
int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int count = 10;
        int runprod = 9;
        int num = 9;
        for(int i = 2; i <= n; ++i){
            runprod *= num;
            count += runprod;
            --num;
        }
        return count;
    }


/*
Idea: count the confusing numbers by the number length:
* if the current number length is fewer than N, then the current number is less than N and we can count these numbers directly;
* else, we consider the numbers with current digit less than the digit of N on the same position [as (N / p) % 10 in the code] and continue to the next position.
Besides, for easier implement, we count all the numbers consisting of {0, 1, 6, 8, 9} [by countAll(int) function in the code] and the invalid confusing number (the reversed number is same to the origin) [by countSame(int) function] individually.
Totally, the complexity of the algorithm is the length of N: log(N).
 */

class Solution {
public:
    using LL = long long;
    unordered_set<int> set = {0, 1, 6, 8, 9};

    int countAll(int N){
        LL k = 1, p = 1;
        while(p * 10 <= N) k ++, p *= 10;
        int rnt = 0;
        while(k){
            int v = (N / p) % 10, cnt = 0;
            for(auto& p: set) if(p < v) cnt ++;
            rnt += cnt * pow(5, k - 1);
            if(!set.count(v)) break;
            k --;
            p /= 10;
        }
        if(k) rnt --;
        return rnt;
    }

    int countSame(int N){
        LL k = 1, p = 1;
        while(p * 10 <= N) k ++, p *= 10;
        // count number with digits fewer than k.
        int rnt = 0, isFirst = 1;
        for(int i = 1; i < k; i ++){
            if(i == 1) rnt += 2;
            else if(i & 1) rnt += 4 * 3 * pow(5, (i + 1) / 2 - 2);
            else rnt += 4 * pow(5, (i + 1) / 2 - 1);
        }
        // we only consider the first half of the digits and the lefts are determined accordingly.
        int kk = k / 2;
        while(kk){
            int v = (N / p) % 10;
            int cnt = 0;
            for(auto& p: set) cnt += p < v;
            if(isFirst) cnt --, isFirst = false;
            if(k & 1) rnt += cnt * pow(5, kk - 1) * 3;
            else rnt += cnt * pow(5, kk - 1);
            if(!set.count(v)) break;
            kk --;
            p /= 10;
        }
        // check if the number of same first half with N is valid.
        if(kk == 0){
            if(k & 1){
                int v = (N / p) % 10;
                if(v > 8) rnt += 3;
                else if(v > 1) rnt += 2;
                else if(v > 0) rnt ++;
                if(v != 0 && v != 1 && v != 8)
                    return rnt;
            }
            vector<int> digits;
            int NN = N;
            while(NN) digits.push_back(NN % 10), NN /= 10;
            for(int i = 0; i < digits.size() / 2; i ++){
                digits[i] = digits[digits.size() - 1 - i];
                if(digits[i] == 6) digits[i] = 9;
                else if(digits[i] == 9) digits[i] = 6;
            }
            LL isSame = 0;
            for(LL i = 0, j = 1; i < digits.size(); i ++, j *= 10) isSame += (LL) j * digits[i];
            if(isSame <= N) rnt ++;
        }
        return rnt;
    }

    int confusingNumberII(int N) {
        // cout<<countAll(N)<<" "<<countSame(N)<<endl;
        return countAll(N) - countSame(N) + (N <= 9);
    }
};

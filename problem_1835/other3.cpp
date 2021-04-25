/*
Just go bit by bit.

Start from LSB, if there are cnt1 no of set bits in arr1 and cnt2 no of set bits in arr2,
then we can have cnt1 * cnt2 no of total pairs of set bits after doing bitwise AND of bits
at LSB of arr1 and arr2.

We only care about set bits during AND operation because it will help in calculating XOR.
So far, we know how many set bits are there at each of the bit positions.

We know that if we have odd no of set bits at any bit position i, then only the value will be 1 at
that bit position i. And the contribution of the bit position i will be (1<<i) .

We can do so for each bit position.
*/

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for(int i = 0; i < 32; ++i){

            long cnt1 = 0, cnt2 = 0;
            for(int num: arr1){
                int bit = (num>>i)&1;
                if(bit) cnt1++;
            }
            for(int num: arr2){
                int bit = (num>>i)&1;
                if(bit) cnt2++;
            }
            long cnt = (cnt1*cnt2);
            if(cnt&1) ans += (1<<i);
        }
        return ans;
    }
};

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int val = 0;
            int cnt = 0;
            for(int j = 1; j * j <= num; j++) {
                if(num % j == 0) {
                    cnt++;
                    val += j;
                    if(j != num / j && (num % (num / j)) == 0) {
                        val += (num / j);
                        cnt++;
                    }
                }
                if(cnt > 4)
                    break;
            }
            if(cnt == 4) {
                ans += val;
            }
        }
        return ans;
    }
};

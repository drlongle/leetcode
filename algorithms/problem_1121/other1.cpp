/*
maxRepeat is the main number we're calculating: the number of instances of the most repeated number in the input. It determines our final answer, because each of those repetitions will need to go into a separate subsequence. To accommodate maxRepeat subsequences of length K or greater, we need maxRepeat * K <= N.
*/
class Solution {
public:
  bool canDivideIntoSubsequences(vector<int>& nums, int K) {
    int const N = nums.size();
    int maxRepeat = 0;
    int lastNum = 0;
    int repeat = 0;
    for (int num : nums) {
      if (num == lastNum) {
        ++repeat;
      } else {
        maxRepeat = max(maxRepeat, repeat);
        lastNum = num;
        repeat = 1;
      }
    }
    maxRepeat = max(maxRepeat, repeat);
    return maxRepeat * K <= N;
  }
};


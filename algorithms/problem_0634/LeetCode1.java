/*
in order to generate the derangements of this array, assume that firstly, we move the number 1 from its original position and place at the place of the number i. But, now, this i-th
  position can be chosen in n-1 ways. Now, for placing the number i we have got two options:

We place i at the place of 1: By doing this, the problem of finding the derangements reduces to finding the derangements of the remaining n−2 numbers, since we've got n−2 numbers and n−2 places, such that every number can't be placed at exactly one position.

We don't place i at the place of 1: By doing this, the problem of finding the derangements reduces to finding the derangements for the n−1 elements(except 1). This is because, now we've got n−1 elements and these n−1 elements can't be placed at exactly one location(with i not being placed at the first position).

 */

public class Solution {
    public int findDerangement(int n) {
        Integer[] memo = new Integer[n + 1];
        return find(n, memo);
    }
    public int find(int n, Integer[] memo) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 0;
        if (memo[n] != null)
            return memo[n];
        memo[n] = (int)(((n - 1L) * (find(n - 1, memo) + find(n - 2, memo))) % 1000000007);
        return memo[n];
    }
}

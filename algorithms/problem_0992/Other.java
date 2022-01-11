class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        int[] count = new int[A.length+1];
        int distinct = 0, start = 0, minEnd = 0, total = 0;
        while (distinct == K || minEnd < A.length) {
            while (distinct < K && minEnd < A.length) 
			    if (count[A[minEnd++]]++ == 0) distinct++;
            int maxEnd = minEnd;
            while (maxEnd < A.length && count[A[maxEnd]] > 0)
			    maxEnd++;
            while (distinct == K) {
                if (count[A[start++]]-- == 1) distinct--;
                total += (maxEnd - minEnd + 1);
            }
        }
        return total;
    }
}

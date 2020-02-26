/*
Explanation
The total sum always bigger than all elements.
We can decompose the biggest number.
Each round we get the current maximum value,
delete it by the sum of other elements.

Time O(N) to build up the priority queue.
Time O(logMaxAlogN)) for the reducing value part.
We have O(maxA) loops, which is similar to gcd
Space O(N)

% operation is totally much more important than using heap.
If brute force solution is accepted,
then the solutions without % are right and good.

But the truth is that, solution without % should be TLE.
So I afraid that, without % is wrong to me.
*/

class Solution {
public:
    bool isPossible(vector<int>& A) {
        long total = 0;
        int n = A.size(), a;
        priority_queue<int> pq(A.begin(), A.end());
        for (int a : A)
            total += a;
        while (true) {
            a = pq.top(); pq.pop();
            total -= a;
            if (a == 1 || total == 1)
                return true;
            if (a < total || total == 0 || a % total == 0)
                return false;
            a %= total;
            total += a;
            pq.push(a);
        }
    }

};

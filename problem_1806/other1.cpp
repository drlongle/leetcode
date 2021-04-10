/*
Graph Thinking

In this method we are making a graph consisting of:
Nodes : i values
Edges : from curr i to new i
2.1) even then i/2
2.2) odd then (n-1+i)/2

You can quickly see that this will form a graph like structure, where each node will have
only 1 out going edge and 1 incoming egde. For example try n = 16

0 -> 0
1 -> 2 -> 4 -> 8 -> 1
3 -> 9 -> 12 -> 6 -> 3
5 -> 10 -> 5
7 -> 11 -> 13 -> 14 -> 7

Notice these are all loops of certain lengths. This is important because we need to come
back to our original permutation and the longest len loop will help us do this.

I don't have the proof for this but I noticed that the loop containing 1 will always be
the longest and will be the LCM of all the other loop lengths

for n = 16
LCM(1, 2, 4) = 4 (which is our answer)

From the above implementation we learnt that we can simply track the loop starting
from 1 and not worry about the other loops as they don't contribute to our answer.
*/

class Solution {
public:
    int reinitializePermutation(int n)
    {
        int ans = 1;
        int curr = n/2; // we start at node 1 itself { (n-1+1)/2 }
        while(curr != 1)
        {
            curr = (curr&1) ? (n-1+curr)/2 : curr/2;
            ans++;
        }

        return ans;
    }
};

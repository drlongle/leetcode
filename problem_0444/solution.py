/*
444. Sequence Reconstruction

Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs.
The org sequence is a permutation of the integers from 1 to n, with 1 <= n <= 10^4. Reconstruction means
building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all
sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be
reconstructed from seqs and it is the org sequence.

Example 1:

Input: org: [1,2,3], seqs: [[1,2],[1,3]]
Output: false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that
can be reconstructed.

Example 2:
Input: org: [1,2,3], seqs: [[1,2]]
Output: false
Explanation: The reconstructed sequence can only be [1,2].

Example 3:
Input: org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
Output: true
Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].

Example 4:
Input: org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
Output: true
*/

class Solution(object):
    def sequenceReconstruction(self, org, seqs):
        """
        :type org: List[int]
        :type seqs: List[List[int]]
        :rtype: bool
        """
        size = len(org)
        indeg = [0] * size
        sucset = [set() for x in range(size)]
        if not seqs: return False
        for seq in seqs:
            if any(s > size or s < 1 for s in seq):
                return False
            for i in range(1, len(seq)):
                if seq[i] not in sucset[seq[i - 1] - 1]:
                    indeg[seq[i] - 1] += 1
                    sucset[seq[i - 1] - 1].add(seq[i])

        q = [i for i in org if not indeg[i - 1]]
        for x in range(size):
            if len(q) != 1 or q[0] != org[x]:
                return False
            nq = []
            for suc in sucset[q[0] - 1]:
                indeg[suc - 1] -= 1
                if not indeg[suc - 1]:
                    nq.append(suc)
            q = nq
        return True

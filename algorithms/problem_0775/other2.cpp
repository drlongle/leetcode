/*
We note that all local inversion is global inversion but not vice versa always.
We need to find if global inversion == local inversion.

When this happens (global inversion == local inversion)? => Only when every global inversion is a local inversion.

When does inversion happen? => When an element is displaced from its original position in sorted array

When an element is displaced 1 distance from its original position it makes only 1 global and local
inversion ([1,0,2]), which makes global inversion == local inversion.

If an element is displaced K>1 distance from its original position then it makes 1 local inversion but K
global inversions ([1,2,0]), which makes global inversion != local inversion.

So it is sufficient to find a global inversion which is not local inversion.
So we need to find if any element is displaced more than 1 distance from its original position in sorted array.

Element Displacement distance = abs(A[i] - i)
 */

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        for(int i=0;i<n;i++)
            if(abs(A[i]-i)>1) return false;

        return true;
    }
};

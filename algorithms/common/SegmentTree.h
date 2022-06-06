#pragma once

#include <cmath>
#include <vector>

class SegmentTree {
  public:
    // A utility function to get the middle index from corner indexes.
    int getMid(int s, int e) { return s + (e - s) / 2; }

    /* A recursive function to get the sum of values in the given range
        of the array. The following are parameters for this function.

        st --> Pointer to segment tree
        si --> Index of current node in the segment tree. Initially
                0 is passed as root is always at index 0
        ss & se --> Starting and ending indexes of the segment represented
                    by current node, i.e., st[si]
        qs & qe --> Starting and ending indexes of query range */
    int getSumUtil(int ss, int se, int qs, int qe, int si) {
        // If segment of this node is a part of given range, then return
        // the sum of the segment
        if (qs <= ss && qe >= se)
            return st[si];

        // If segment of this node is outside the given range
        if (se < qs || ss > qe)
            return 0;

        // If a part of this segment overlaps with the given range
        int mid = getMid(ss, se);
        return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
               getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
    }

    /* A recursive function to update the nodes which have the given
    index in their range. The following are parameters
        st, si, ss and se are same as getSumUtil()
        i --> index of the element to be updated. This index is
                in the input array.
    diff --> Value to be added to all nodes which have i in range */
    void updateValueUtil(int ss, int se, int i, int diff, int si) {
        // Base Case: If the input index lies outside the range of
        // this segment
        if (i < ss || i > se)
            return;

        // If the input index is in range of this node, then update
        // the value of the node and its children
        st[si] = st[si] + diff;
        if (se != ss) {
            int mid = getMid(ss, se);
            updateValueUtil(ss, mid, i, diff, 2 * si + 1);
            updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
        }
    }

    // The function to update a value in input array and segment tree.
    // It uses updateValueUtil() to update the value in segment tree
    void updateValue(int i, int new_val) {
        // Check for erroneous input index
        if (i < 0 || i > n - 1) {
            return;
        }

        // Get the difference between new value and old value
        int diff = new_val - arr[i];

        // Update the value in array
        arr[i] = new_val;

        // Update the values of nodes in segment tree
        updateValueUtil(0, n - 1, i, diff, 0);
    }

    // Return sum of elements in range from index qs (query start)
    // to qe (query end). It mainly uses getSumUtil()
    int getSum(int qs, int qe) {
        // Check for erroneous input values
        if (qs < 0 || qe > n - 1 || qs > qe) {
            return -1;
        }

        return getSumUtil(0, n - 1, qs, qe, 0);
    }

    // A recursive function that constructs Segment Tree for array[ss..se].
    // ss and se: begin and end of data's interval
    // si is index of current node in segment tree st
    int constructSTUtil(int ss, int se, int si) {
        // If there is one element in array, store it in current node of
        // segment tree and return
        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }

        // If there are more than one elements, then recur for left and
        // right subtrees and store the sum of values in this node
        int mid = getMid(ss, se);
        st[si] = constructSTUtil(ss, mid, si * 2 + 1) +
                 constructSTUtil(mid + 1, se, si * 2 + 2);
        return st[si];
    }

    /* Function to construct segment tree from given array. This function
    allocates memory for segment tree and calls constructSTUtil() to
    fill the allocated memory */
    SegmentTree(std::vector<int> &a) : arr(a) {

        n = arr.size();
        // Allocate memory for the segment tree

        // Height of segment tree
        int x = (int)(std::ceil(std::log2(n)));

        // Maximum size of segment tree
        int max_size = 2 * (int)pow(2, x) - 1;

        // Allocate memory
        st.assign(max_size, 0);

        // Fill the allocated memory st
        constructSTUtil(0, n - 1, 0);
    }

    std::vector<int> arr; // input data
    std::vector<int> st;  // segment tree
    int n;                // segment tree's size
};
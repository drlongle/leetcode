/*
 Binary index tree (Fernwick tree)

 Step 1: Implement the Binary Indexed Tree. Since the tree is initialized to all zeros,
 only update and query is needed to implement.

 Step 2: Iterate over instructions. For each element:
 Calculate the left cost (smaller cost) and right cost (larger cost).
 Add the minimal one to the total cost.
 Update the element into the Binary Indexed Tree.

 Step 3: Return the total cost after iteration.
 */

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int m = 100002;
        vector<int> bit(m);
        long cost = 0;
        long MOD = 1000000007;
        int n = instructions.size();

        for (int i = 0; i < n; i++) {
            int leftCost = query(instructions[i] - 1, bit);
            int rightCost = i - query(instructions[i], bit);
            cost += min(leftCost, rightCost);
            update(instructions[i], 1, bit, m);
        }
        return (int)(cost % MOD);
    }

    // implement Binary Index Tree
    void update(int index, int value, vector<int>& bit, int m) {
        index++;
        while (index < m) {
            bit[index] += value;
            index += index & -index;
        }
    }

    int query(int index, vector<int>& bit) {
        index++;
        int result = 0;
        while (index >= 1) {
            result += bit[index];
            index -= index & -index;
        }
        return result;
    }
};
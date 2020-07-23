/*
We can transform the problem to the following:
How many "different" lines do we have in the input matrix.
Here "different" means lines that even inverted are not equal to each other.
We create hash of each line and check the number of lines for each hash and
return the maximal.
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<unsigned long long, int> lines;
        int res = 0;
        for (auto& x : matrix) {
           res = max(res, ++lines[to_key(x)]);
        }
        return res;
    }
    
    unsigned long long to_key(vector<int> & row) {
       bool invert = row[0] == 1;
       unsigned long long key = 0;
       for (int i : row) {
          if (invert) i = !i;
          key = (key << 1) | i;
       }
       return key;
    }
};

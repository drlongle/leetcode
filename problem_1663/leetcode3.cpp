class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 0);
        for (int position = n - 1; position >= 0; position--) {
            int add = min(k - position, 26);
            result[position] = (char)(add + 'a' - 1);
            k -= add;
        }
        return result;
    }
};

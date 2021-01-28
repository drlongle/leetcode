class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 'a');
        k -= n;
        for (int position = n - 1; position >= 0 && k > 0; position--) {
            int add = min(k, 25);
            result[position] = (char)(result[position] + add);
            k -= add;
        }
        return result;
    }
};
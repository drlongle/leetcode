class Solution {
  public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> forward(n, 0), backward(n, 0), res(n, 0);
        for (int i = 0, s = 0, balls = 0; i < n; ++i) {
            forward[i] = s;
            balls += boxes[i] - '0';
            s += balls;
        }

        for (int i = n - 1, s = 0, balls = 0; i >= 0; --i) {
            backward[i] = s;
            balls += boxes[i] - '0';
            s += balls;
        }

        for (int i = 0; i < n; ++i) {

            res[i] = forward[i] + backward[i];
        }

        return res;
    }
};

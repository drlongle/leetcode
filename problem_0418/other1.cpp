class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int num = sentence.size();
        int dp[num];
        int ret = 0;

        // If the i-th word starts a line, how many words can we have in that line?
        for (int i = 0; i < num; i++) {
            int size = 0;
            int cnt = 0;
            int start = i;

            while (size <= cols) {
                size += sentence[start].size();
                start = (start + 1) % num;
                cnt++;
                if (size < cols)
                    size++;
            }
            dp[i] = cnt - 1;
        }

        for (int i = 0, k = 0; i < rows; i++) {
            ret += dp[k];
            k = (k + dp[k]) % num;
        }

        return ret/num;
    }
};

class Solution {
public:
    int minOperations(vector<int>& n1, vector<int>& n2) {
        if (n2.size() * 6 < n1.size() || n1.size() * 6 < n2.size())
            return -1;
        int sum1 = accumulate(begin(n1), end(n1), 0), sum2 = accumulate(begin(n2), end(n2), 0);
        if (sum1 > sum2)
            swap(n1, n2);
        make_heap(begin(n1), end(n1), greater<int>());
        make_heap(begin(n2), end(n2));
        int cnt = 0, diff = abs(sum1 - sum2);
        while (diff > 0) {
            ++cnt;
            if (n1.empty() || (!n2.empty() && n2.front() - 1 > 6 - n1.front())) {
                diff -= n2.front() - 1;
                pop_heap(begin(n2), end(n2)); n2.pop_back();
            } else {
                diff -= 6 - n1.front();
                pop_heap(begin(n1), end(n1), greater<int>()); n1.pop_back();
            }
        }
        return cnt;
    }
};

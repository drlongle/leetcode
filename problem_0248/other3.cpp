class Solution {
public:
    void backtrack(long long low, long long high, int left, int right, string cur,
                   const unordered_set<string>& myset, int &cnt)
    {
        if (left > right) {
            long long number = stoll(cur);
            if (number >= low && number <= high)
                cnt++;
            return;
        }

        if (left == right) {
            cur[left] = '0';
            backtrack(low, high, left + 1, right -1, cur, myset, cnt);
            cur[left] = '8';
            backtrack(low, high, left + 1, right - 1, cur, myset, cnt);
            cur[left] = '1';
            backtrack(low, high, left+1, right - 1, cur, myset, cnt);
            return;
        }

        for (auto it : myset) {
            if (left == 0 && it[0] == '0')
                continue;

            cur[left] = it[0];
            cur[right] = it[1];

            backtrack(low, high, left+1, right-1, cur, myset, cnt);
        }
    }

    int strobogrammaticInRange(string low, string high) {
        unordered_set<string> myset;
        int low_size = low.size();
        int high_size = high.size();
        long long high_num = stoll(high);
        long long low_num = stoll(low);
        int cnt = 0;
        int size;

        myset.insert("69");
        myset.insert("11");
        myset.insert("88");
        myset.insert("96");
        myset.insert("00");

        for (size = low_size; size <= high_size; size++) {
            string cur(size, 0);
            backtrack(low_num, high_num, 0, size - 1, cur, myset, cnt);
        }

        return cnt;
    }
};

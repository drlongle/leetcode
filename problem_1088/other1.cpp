class Solution {
public:
    unordered_map<int, int> map = {{0,0}, {1, 1}, {6, 9}, {9,6}, {8, 8}};
    int range = 0;
    int count = 0;
    int confusingNumberII(int N) {
        range = N;
        count = 0;

        dfs(0, 0, 1);
        return count;
    }

    void dfs(long num, long reverse_num, long base) {
        if (num > range)
            return;

        if (num != reverse_num)
            count++;

        for (auto &m : map) {
            int candidate = m.first;

            if (num == 0 && candidate == 0)
                continue; //skip 0, start from 1, but 10 is good

            dfs(num * 10 + candidate, map[candidate] * base + reverse_num, base * 10);
        }
    }
};

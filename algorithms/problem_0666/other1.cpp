class Solution {
public:
    int pathSum(vector<int>& nums) {

        int N = nums.size();

        int level = 0, pos = 0, val = 0;

        for (const auto & n : nums)
        {
            level = n / 100;
            pos   = (n % 100) / 10;
            val   = (n % 100) % 10;
            record[level][pos] = val;
        }

        int cur = 0, sum = 0;

        dfs(1, 1, cur, sum);

        return sum;
    }

    void dfs(int level, int pos, int cur, int& sum)
    {
        cur += record[level][pos];
        if (!record[level+1].count(pos*2) && !record[level+1].count(pos*2 -1))
        {
            sum += cur;
            return;
        }

        if (record.count(level+1) && record[level+1].count(2*pos-1))
            dfs(level+1, pos*2 - 1, cur, sum);

        if (record.count(level+1) && record[level+1].count(2*pos))
            dfs(level+1, pos*2, cur, sum);
    }

private:
    map<int, map<int, int>> record;
};

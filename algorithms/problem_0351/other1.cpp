class Solution
{
public:
    int numberOfPatterns(int m, int n)
    {
        unordered_set<int> s;
        int ret = 0;
        for(int i = 1; i <= 9; i++)
        {
            s.insert(i);
            helper(i, m, n, s, ret);
            s.erase(s.find(i));
        }
        return ret;
    }
    void helper(int idx, int m, int n, unordered_set<int>& s, int& ret)
    {
        if(m <= s.size() && s.size() <= n)
            ret++;
        if(s.size() > n)
            return;
        for(int i = 1; i <= 9; i++)
        {
            if(s.count(i))
                continue;
            if(idx == 1 && i == 3 && !s.count(2))
                continue;
            if(idx == 3 && i == 1 && !s.count(2))
                continue;
            if(idx == 1 && i == 7 && !s.count(4))
                continue;
            if(idx == 7 && i == 1 && !s.count(4))
                continue;
            if(idx == 1 && i == 9 && !s.count(5))
                continue;
            if(idx == 9 && i == 1 && !s.count(5))
                continue;
            if(idx == 7 && i == 9 && !s.count(8))
                continue;
            if(idx == 9 && i == 7 && !s.count(8))
                continue;
            if(idx == 9 && i == 3 && !s.count(6))
                continue;
            if(idx == 3 && i == 9 && !s.count(6))
                continue;
            if(idx == 1 && i == 7 && !s.count(4))
                continue;
            if(idx == 8 && i == 2 && !s.count(5))
                continue;
            if(idx == 2 && i == 8 && !s.count(5))
                continue;
            if(idx == 3 && i == 7 && !s.count(5))
                continue;
            if(idx == 7 && i == 3 && !s.count(5))
                continue;
            if(idx == 4 && i == 6 && !s.count(5))
                continue;
            if(idx == 6 && i == 4 && !s.count(5))
                continue;
            s.insert(i);
            helper(i, m, n, s, ret);
            s.erase(s.find(i));
        }
        return;
    }
};

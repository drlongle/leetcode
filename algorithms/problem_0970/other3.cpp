class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        vector<int> vx;
        fill(x, vx, bound);

        vector<int> vy;
        fill(y, vy, bound);

        unordered_set<int> resSet;
        for (int i = 0; i < vx.size(); i++)
            for (int j = 0; j < vy.size(); j++)
                if (int p = vx[i] + vy[j]; p <= bound)
                    resSet.insert(p);
                else
                    break;

        return vector<int>(resSet.begin(), resSet.end());
    }
private:
    void fill(int x, vector<int>& v, int bound)
    {
        v.reserve(20);
        if (x == 1)
            v.push_back(1);
        else
            for (int n = 1; n < bound; n *= x)
                v.push_back(n);
    }
};

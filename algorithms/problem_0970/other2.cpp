class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> powx;
        vector<int> powy;
        powx.push_back(1);
        powy.push_back(1);
        int i = 0;
        if (x != 1)
        {
            while(powx[i] <= bound)
            {
                powx.push_back(powx[i]*x);
                i = i+1;
            }
        }
        i = 0;
        if (y != 1)
        {
            while(powy[i] <= bound)
            {
                powy.push_back(powy[i]*y);
                i = i+1;
            }
        }
        set<int>s;
        for (int j = 0 ; j < powx.size(); j++)
        {
            for (int k = 0 ; k < powy.size(); k++)
            {
                int sum = powx[j] + powy[k];
                if (sum<=bound)
                    s.insert(sum);
            }
        }
        vector<int>ans;
        for (const auto & i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};

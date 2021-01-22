class Solution {
public:
    int maximumSwap(int num) {
        unordered_map<int,int>dict;
        string snum = to_string(num);

        for(int i = 0; i < snum.size(); i++)
        {
            dict[snum[i] - '0'] = i;
        }

        for(int i = 0; i < snum.size(); i++)
        {
            for(int d = 9; d > (snum[i] - '0'); d--)
            {
                if(dict[d] > i)
                {
                    swap(snum[i], snum[dict[d]]);
                    return stoi(snum);
                }
            }
        }

        return num;
    }
};

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s=to_string(N);
        sort(s.begin(),s.end());
        do {
            if(s[0]!='0')
            {
                int a=stoi(s);
                if ((a & (a-1)) == 0)
                    return true;
            }
        } while(next_permutation(s.begin(),s.end()));

        return false;
    }
};

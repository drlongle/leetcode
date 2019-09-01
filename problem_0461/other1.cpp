class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int a = x ^ y;
        string s = bitset<32>(a).to_string();
        int count = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                count++;
        return count;
    }
};

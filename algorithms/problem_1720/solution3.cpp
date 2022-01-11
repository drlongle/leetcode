class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        for (int i = 0; i < n; ++i) {
            swap(first, encoded[i]);
            first ^= encoded[i];
        }
        encoded.push_back(first);
        
        return encoded;
    }
};


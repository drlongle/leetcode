class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        for (int i = 0; i < n; ++i) {
            int temp = encoded[i];
            encoded[i] = first;
            first ^= temp;
        }
        encoded.push_back(first);
        
        return encoded;
    }
};


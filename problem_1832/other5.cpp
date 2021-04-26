class Solution {
public:
    bool checkIfPangram(const string& sentence) {
        int arr[26];
        for(int i=0; i<26; ++i)
            arr[i]=0;

        for(auto i:sentence)
            ++arr[i-'a'];

        for(auto i:arr)
            if(!i) return false;

        return true;
    }
};

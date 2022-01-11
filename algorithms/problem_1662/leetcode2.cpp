class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        vector<char> list1;
        for (auto& s : word1) {
            for (auto& c : s) {
                list1.push_back(c);
            }
        }
        vector<char> list2;
        for (auto& s : word2) {
            for (auto& c : s) {
                list2.push_back(c);
            }
        }
        if (list1.size() != list2.size()) {
            return false;
        }
        int size = list1.size();
        for (int i = 0; i < size; i++) {
            if (list1[i] != list2[i]) {
                return false;
            }
        }
        return true;
    }
};

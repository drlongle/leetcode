class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int stringIndex = 0;
        int characterIndex = 0;
        int word2Length = word2.size();
        vector<int> word2LengthList;
        for (auto s : word2) {
            word2LengthList.push_back(s.size());
        }
        for (auto s : word1) {
            for (auto& c : s) {
                if (stringIndex >= word2Length ||
                    c != word2[stringIndex][characterIndex]) {
                    return false;
                }
                characterIndex++;
                if (characterIndex == word2LengthList[stringIndex]) {
                    stringIndex++;
                    characterIndex = 0;
                }
            }
        }
        return true;
    }
};

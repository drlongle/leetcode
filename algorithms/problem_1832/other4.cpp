class Solution {
public:
    bool checkIfPangram(string sentence) {
        std::vector<int>visited(26, 0);
        int count = 0;
        for(auto c:sentence) {
            if (visited[c-'a'] == 0) {
                visited[c-'a'] = 1;
                ++count;
            }
        }
        return (count == 26);
    }
};

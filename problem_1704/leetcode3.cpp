class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        return countVowel(0, n / 2, s) == countVowel(n / 2, n, s);
    }

    int countVowel(int start, int end, string& s) {
        string vowels = "aeiouAEIOU";
        int answer = 0;
        for (int i = start; i < end; i++) {
            if (vowels.find(s[i]) != string::npos) {
                answer++;
            }
        }
        return answer;
    }
};

/*

Intuition
If a string have ocurrences x times,
any if its substring must appear at least x times.
There must be a substring of length minSize, that has the most ocurrences.
So that we just need to count the ocurrences of all subtring with length minSize.

Explanation
Find the maximum ocurrences of all substrings with length k = minSize
*/

class Solution {
public:
    unordered_map<string, int> hash;
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res = 0;
        for(int i=minSize; i<=minSize; ++i) {  // only minSize !!!
            res = max(res, maxFreqFixSize(s, maxLetters, i));
        }
        return res;
    }
    
    int maxFreqFixSize(const string &s, int maxLetters, int fixSize) {
        int res = 0;
        for(int i=0; i+fixSize<=s.size(); ++i) {
            string sub = s.substr(i, fixSize);
            unordered_set<char> uniq(sub.begin(), sub.end());
            if(hash.count(sub)>0 || uniq.size()<=maxLetters) {
                hash[sub]++;
                res = max(res, hash[sub]);
            }  
        }
        return res;  
    } 
};

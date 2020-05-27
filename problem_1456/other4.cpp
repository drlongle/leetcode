class Solution {// Sliding Window
public://Time/Space: O(N); O(1)
    int maxVowels(string s, int k) {
        unordered_set<char> dict{'a','e','i','o','u'};
        int ans = 0;
        for(int i = 0, cnt = 0; i < s.size() && ans < k; i++){  // ans < k is pruning 
            if(dict.count(s[i])) cnt++;
            if(i >= k - 1) ans = max(ans, cnt);
            if(i >= k - 1 && dict.count(s[i -k + 1])) cnt--;            
        }
        return ans;
    }
};

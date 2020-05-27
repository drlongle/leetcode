class Solution {// Sliding Window
public://Time/Space: O(N); O(1)
    int maxVowels(string_view s, int k) {
        static int dict[26]={1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        int ans = 0;
        for(int i = 0, cnt = 0; i < s.size() && ans < k; i++){   // ans < k is pruning          
            if(dict[s[i] - 'a']) ans = max(ans, ++cnt);            
            if(i >= k - 1 && dict[s[i -k + 1]  - 'a']) cnt--;            
        }
        return ans;
    }
};

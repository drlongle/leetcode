class Solution {
public:
    string pushDominoes(string s) {
        int left= 0, right= 0, n= s.length();
        while (right<n) {
            while (s[left]=='L') left++;
            if (right<=left) right= left+1;
            while (right<n and s[right]=='.') right++;
            if (right>=n) break;

            if (s[right]=='L' and s[left]=='.')
                while (left < right) s[left++]='L';

                else if (s[right]=='L' and s[left]=='R') {
                    int front= right-1, back= left+1;
                    while (back<front) {s[back++]='R'; s[front--]='L';}
                    left= right;
                }

                else if (s[right]=='R' and s[left]=='.') left= right;

                else if (s[right]=='R' and s[left]=='R')
                    while (left<right) s[left++]='R';
        }
        if (s[left]=='R') while (left<n) s[left++]='R';
        return s;
    }
};

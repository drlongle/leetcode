class Solution {
public:
    vector<int> findPermutation(string s) {
        int len = s.size();
        int n= len+1;
        vector <int> res ;
        for (int i=1; i<=n; i++)
            res.push_back(i);

        int pos=0;
        while (pos<s.size())
        {
            int left=pos;
            // find subsequence of D..D
            while (s[left]!='D' && left<s.size())
                left++;
            if (left==s.size())
                break;
            int right = left;

            // be careful, find first non D
            while (s[right]=='D'&& right<s.size())
                right++;
            // right is fine to be after last D

            reverse (res.begin()+ left, res.begin()+ right+1); // we +1 to get pass , the right bound is non-inclusive.

            pos= right;
        }

        return res;
    }
};

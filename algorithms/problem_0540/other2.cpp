class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l = 0, h = a.size()-1;
        while(l < h) {
            int m = l + (h-l)/2;
            bool higher_even = (h-m+1) % 2 == 0;
            if(m + 1 <= h && a[m] == a[m+1]) {
                if(higher_even) {
                    h = m-1;
                } else {
                    l = m + 2;
                }
            } else if(m - 1 >= l && a[m] == a[m-1]) {
                if(higher_even) {
                    l = m+1;
                } else {
                    h = m-2;
                }             
            } else {
                return a[m];
            }
        }
        return a[l];
    }
};

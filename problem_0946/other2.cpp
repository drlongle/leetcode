class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0,k=0,n=pushed.size();
        while(i<n) {
            pushed[k] = pushed[i];
            k++;
            while(j<n && k>0 && pushed[k-1] == popped[j]) {
                j++;
                k--;
            }
            i++;
        }
        return j == n;
    }
};

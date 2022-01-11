class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length());
        int left=0,right=0;
        for(int i=0;i<boxes.length();i++)
        {
            if(boxes[i]=='1') ans[0]+=i,right++;
        }
        if(boxes[0]=='1') left++,right--;
        for(int i=1;i<boxes.length();i++)
        {
            ans[i]=ans[i-1]-right+left;
            if(boxes[i]=='1') left++,right--;
        }
        return ans;
    }
};

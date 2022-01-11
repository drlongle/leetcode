class Solution {
public:
    vector<int> findPermutation(string s) {

        int size = s.size();
        vector<int> ans(size+1,1);
        int count =0;
        //this will have largest number used till now
        int largestUsed =1;
        int i=0;
        while(i<size)
        {
            if(s[i]=='I')
            {
                //when you find I the next number will be 1 more than biggest number used and updating largest number too
                ans[i+1]=++largestUsed;
                ++i;
            }
            else
            {
                //when you find the count how many continuous D are there and increment count
                while(i+count<size && s[i+count]=='D') {++count;}
                //the current number will be added with count
                ans[i]+=count--;
                //updating the largest used number used
                largestUsed=ans[i++];
                //subsequent number will be one less than last number
                while(count-->0){ ans[i]=ans[i-1]-1;++i;}
                ans[i]=ans[i-1]-1;
            }

            count =0;
        }
        return ans;

    }
};

class Solution {
public:
    int minFlips(string s) {

        int n=s.length();
        int ans=INT_MAX,cnt1=0,cnt2=0;
        string s1(s);
        s1=s1+s;

        //generating model strings for comparison
        string comp1="",comp2="";
        for(int i=0;i<2*n;++i)
        {
            if(i%2==0)
            {
                comp1+='0';//010101.....
                comp2+='1';//10101....
            }
            else{
                comp1+='1';//010101...
                comp2+='0';//10101...
            }
        }

        int i=0,j=0; //pointers to mark window

        for( ;j<2*n;++j)
        {
            //calcultions
            if(s1[j]!=comp1[j])
            {
                ++cnt1;

            }
            if(s1[j]!=comp2[j])
            {
                ++cnt2;
            }

            //window size less
            if(j-i+1<n)
            {
                continue;
            }
                //window size hit
            else {
                //"window size hit:"
                //calculate ans from this window
                if(ans>min(cnt1,cnt2))
                {
                    ans=min(cnt1,cnt2);
                }
                //slide window
                //remove all calculations for old window
                if(s1[i]!=comp1[i])
                {
                    --cnt1;
                }
                if(s1[i]!=comp2[i])
                {
                    --cnt2;
                }
                ++i;//increment i to slide window ahead
            }
        }

        return ans;
    }
};

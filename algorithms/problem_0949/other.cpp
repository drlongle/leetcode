class Solution {
    vector<string> permutations;
    string maxstring="";
public:
    void swap(int *a,int *b)
    {
        int t=*a;
        *a=*b;
        *b=t;
    }
    void permute(vector<int> &A, int i)
    {
        if (i==4)
        {
            string time="";
            for (int k=0;k<4;++k)
            {
                time+='0'+A[k];
            }
            string hour=time.substr(0,2);
            string min=time.substr(2,2);
            if (hour>="00" && hour<="23" && min>="00" && min<="59")
            {
                if (time>maxstring)
                    maxstring=time;
            }
            return;
        }
        for (int j=i;j<4;++j)
        {
            swap(&A[i],&A[j]);
            permute(A,i+1);
            swap(&A[i],&A[j]);
        }
    }
    string largestTimeFromDigits(vector<int>& A) {
        permute(A,0);
        if (maxstring.length()==0)
            return "";
        maxstring.insert(2,":");
        return maxstring;
    }
};

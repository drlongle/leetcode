/*
the basic approach behind this solution is that-

1. We first find the basic palindrome i.e. simply copying the first half element to second half.
2. Using this basic palindrome we find the palindrome greater and smaller to this palindrome as follows
  A. we find the mid (both mid if size is even)
  B. we then find the smaller palindrome by-
    a.using two variable i and j pointing to mid/both mid.
    b.decreasing ith and jth element by 1 and then moving j backward till 0 and i forward till last.
    c. if j==0 and string[j]=1 then we will decrease the string size.
  C. Similarly we find the larger palindrome like this.
3. at last we will find the closest number(smaller vs greater pallindrome) to the given input .
4. if both are at same difference we will return smaller one else we will return the closest one to the input.
*/

class Solution {
public:
    bool isPalindrome(string& temp)
    {
        if(temp.size()==1)
        {
            return true;
        }
        int i=0;
        for(int j=temp.size()-1;j>i;j--,i++)
        {
            if(temp[i]!=temp[j])
                return false;
        }
        return true;
    }
    void increaseLength(string& temp)
    {
        temp.push_back(0);
        for(int i=temp.size()-1;i>1;i--)
        {
            temp[i]=temp[i-1];
        }
        temp[1]='0';
        temp[0]='1';
    }
    void decreaseLength(string& temp)
    {
        for(int i=0;i<temp.size()-1;i++)
        {
            temp[i]=temp[i+1];
        }
        temp.pop_back();
    }
    inline string compare(string a,string b)
    {
        if(a.size()<b.size())
            return a;
        if(a.size()>b.size())
            return b;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>b[i])
            {
                return b;
            }
            if(a[i]<b[i])
            {
                return a;
            }
        }
        return a;
    }
    long int difference(string a,string b)
    {
        long long int t1=stoll(a,NULL,10);
        long long int t2=stoll(b,NULL,10);
        long int temp;
        temp=abs(t1-t2);
        return temp;
    }
    void decrease(string& temp,int i,int j)
    {
        if(i==j)
        {
            if(temp[j]=='0')
            {
                temp[j]='9';
                j--;
                i++;
            }
        }
        else
        {
            if(temp[j]=='0')
            {
                temp[j]='9';
                temp[i]='9';
                j--;
                i++;
            }
        }
        while(temp[j]=='0')
        {
            temp[j]='9';
            temp[i]='9';
            j--;
            i++;
        }
        if(j==0)
        {
            if(temp[j]=='1')
            {
                temp[i]='9';
                decreaseLength(temp);
            }
            else
            {
                temp[j]--;
                temp[i]=temp[j];
            }
        }
        else
        {
            temp[j]--;
            temp[i]=temp[j];
        }
    }
    void increase(string& temp,int i,int j)
    {
        if(i==j)
        {
            if(temp[j]=='9')
            {
                temp[j]='0';
                j--;
                i++;
            }
        }
        else
        {
            if(j>0&&temp[j]=='9')
            {
                temp[j]='0';
                temp[i]='0';
                j--;
                i++;
            }
        }
        while(j>0&&temp[j]=='9')
        {
            temp[j]='0';
            temp[i]='0';
            j--;
            i++;
        }
        if(j==0)
        {
            if(temp[j]=='9')
            {
                temp[i]='1';
                increaseLength(temp);
            }
            else
            {
                temp[j]++;
                temp[i]=temp[j];
            }
        }
        else
        {
            temp[j]++;
            temp[i]=temp[j];
        }
    }
    string bigData(string n)
    {
        string temp=n;
        string small,big;
        int i=0;
        int j;
        for(j=n.size()-1;j>i;j--,i++)
        {
            temp[j]=temp[i];
        }
        if(isPalindrome(n))
        {
            small=temp;
            big=temp;
            if(i==j)
            {
                decrease(small,i,i);
                increase(big,i,i);
            }
            else
            {
                decrease(small,i,j);
                increase(big,i,j);
            }
            long int ds,db;
            ds=difference(n,small);
            db=difference(n,big);
            if(ds>db)
            {
                return big;
            }
            else if(ds<db)
            {
                return small;
            }
            else
            {
                return small;
            }
        }
        else
        {
            small=compare(temp,n);
            if(small==n)
            {
                big=temp;
                small=temp;
                if(i==j)
                {
                    decrease(small,i,i);
                }
                else
                {
                    decrease(small,i,j);
                }
            }
            else
            {
                big=temp;
                if(i==j)
                {
                    increase(big,i,i);
                }
                else
                {
                    increase(big,i,j);
                }
            }
            cout<<small<<" "<<big;
            long int ds,db;
            ds=difference(n,small);
            db=difference(n,big);
            if(ds>db)
            {
                return big;
            }
            else if(ds<db)
            {
                return small;
            }
            else
            {
                return small;
            }
        }
    }
    string nearestPalindromic(string n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(n.size()==1)
        {
            if(n[0]=='0')
                return n;
            n[0]=n[0]-1;
            return n;
        }
        return bigData(n);
    }
};

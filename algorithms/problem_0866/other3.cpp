// Idea is to generate the next smallest palindrome in O(length(N)) time and then
// check if it is a prime number or not.

class Solution {
public:
    int nextpalin(int t)
    {
        vector<int> nums;
        bool an=true;
        while(t)
        {
            nums.push_back(t%10);
            t/=10;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=9)
            {
                an=false;
                break;
            }
        }
        if(an)
        {
            string temp="1";
            for(int i=0;i<nums.size()-1;i++)
                temp+='0';
            temp+='1';
            return stoi(temp);
        }
        reverse(nums.begin(),nums.end());
        int size=nums.size();
        int mid=size/2;
        int i=mid-1,j;
        if(size%2!=0)
            j=mid+1;
        else
            j=mid;
        while(i>=0 and j<size and nums[i]==nums[j])
        {
            i--;
            j++;
        }
        if(i<0 or nums[i]<nums[j])
        {
            int i=mid-1,j,k;
            int carry=1;
            if(size%2)
            {
                k=size/2;
                nums[k]+=carry;
                carry=nums[k]/10;
                nums[k]%=10;
                j=mid+1;
            }
            else
                j=mid;
            while (i >= 0)
            {
                nums[i] += carry;
                carry = nums[i] / 10;
                nums[i] %= 10;
                nums[j++] = nums[i--];
            }
        }
        else
        {
            while(i>=0)
                nums[j++]=nums[i--];
        }
        string ans="";
        for(int i=0;i<nums.size();i++)
        {
            ans+=to_string(nums[i]);
        }
        return stoi(ans);
    }
public:
    bool ispalin(int num)
    {
        string g=to_string(num);
        int l=0,h=g.length()-1;
        while(l<h)
        {
            if(g[l]!=g[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
public:
    bool isprime(int num)
    {
        if(num==1)return false;
        int s=sqrt(num);
        for(int i=2;i<=s;i++)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }
public:
    int primePalindrome(int N) {
        if(ispalin(N) and isprime(N))
            return N;
        int ans=-1;
        while(true)
        {
            int np=nextpalin(N);
            if(isprime(np))
            {
                ans=np;
                break;
            }
            N=np;
        }
        return ans;
    }
};

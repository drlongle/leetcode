class Solution
{
public:
    array<string, 5> chars = {"00", "11", "69", "88", "96"};

    void helper(int& ret, int n, string& s, int i, const string& low, const string& high)
    {
        int j = n-i-1;
        if(i>j)
        {
            // make sure we respect the min and max
            if((low.size() == n && s < low) || (high.size() == n && s > high))
                return;
            ++ret;
            return;
        }

        for(int k=0;k<chars.size();++k)
        {
            if(i==0 && k==0 && n!=1)
                continue; // skip zero as the first number except if n==1
            if(i==j && (k==2 || k==4))
                continue; // skip 6 or 9 for the middle part
            s[i] = chars[k][0];
            s[j] = chars[k][1];
            helper(ret, n, s, i+1, low, high);
        }
    }

    int strobogrammaticInRange(const string& low, const string& high)
    {
        int ret = 0;

        if(low.size() == high.size() && low <= high)
        {
            string s;
            s.resize(low.size());
            helper(ret, s.size(), s, 0, low, high);
        }
        else if(low.size() < high.size())
        {
            for(const string& v : {low, high})
            {
                int a = 0;
                string s;
                s.resize(v.size());
                helper(a, s.size(), s, 0, low, high);
                ret += a;
            }

            // no need to generate the actual strobogrammatic numbers. we can just count
            int pow_5 = pow(5, max(0, (int)low.size() / 2 - 1));
            for(int i=low.size()+1;i<high.size();++i)
            {
                if(i>=4&&i%2==0)
                    pow_5 *= 5;
                ret += (i%2==0) ? 4*pow_5 : 12*pow_5;
            }
        }
        return ret;
    }
};

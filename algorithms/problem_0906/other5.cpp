class Solution {
public:

#define ll long long

    bool isPallindrome(string s)
    {
        for(ll i=0;i<s.length()/2;i++)
        {
            if(s[i]!=s[s.length()-i-1])
                return false;
        }
        return true;
    }

    int superpalindromesInRange(string left, string right)
    {

        ll l = stoll(left);
        ll r = stoll(right);

        // rmax = 10^18

        // store all the pallindromes <= 10^9

        vector<ll> v;

        for(ll i=1;i<10;i++)
            v.push_back(i);

        for(ll i=1;i<=1e4;i++)
        {
            string s1 = to_string(i);
            string s2 = to_string(i);
            reverse(s2.begin(),s2.end());

            // even length pallindromes
            v.push_back(stoll(s1+s2));

            // odd length pallidromes

            for(ll j=0;j<10;j++)
            {
                string temp = s1;
                temp+=(j+'0');
                temp+=s2;

                v.push_back(stoll(temp));
            }
        }
        int cnt  = 0 ;
        for(auto it: v)
        {
            if(it>1e9)
                continue;

            ll sq= it*it;

            if(sq <=r and  sq >=l and isPallindrome(to_string(sq)))
                cnt ++;
        }

        return cnt ;
    }
};

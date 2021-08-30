class Solution {
public:
    int confusingNumberII(int N) {
        return valid(N) - symmetry(N);
    }

private:
    unordered_set<int> st = {0,1,6,8,9};
    int nums[10] = {0,1,2,2,2,2,2,3,3,4};
    int ms[10] = {0,1,2,2,2,2,2,2,2,3};
    int valid(int n){
        string t = to_string(n);
        int ret = 0, len = t.size();
        for(char c:t){
            len--;
            ret+= nums[c-'0'] * pow(5, len);
            if(!st.count(c-'0'))
                return ret;
        }
        return ret + 1;
    }

    int symmetry(int n){
        string t = to_string(n);
        int m = t.size(), len = m/2, ret = 1, mid = (m %2 ==1?3:1);
        for(int l = 1;l<m;l++){
            ret += 4 * pow(5, l/2-1) * (l %2 == 1?3:1);
        }
        for(int i = 0;len>0;i++,len--){
            ret+= (nums[t[i]-'0'] + (i==0?-1:0)) * pow(5, len-1)*mid;
            if(!st.count(t[i]-'0'))
                return ret;
        }
        if(m %2==1){
            ret+= ms[t[m/2]-'0'];
            if(t[m/2] != '0' && t[m/2] != '1' && t[m/2] != '8') return ret;
        }

        string y = t.substr(0,m/2);
        if(m % 2 == 1) y.push_back(t[m/2]);
        for(int i = y.size()-1-(m&1);i>=0;i--) y.push_back(rotate(y[i]));
        return ret+(y<=t);
    }

    char rotate(char c){
        if(c == '0' || c == '1' || c== '8') return c;
        else return c== '6' ? '9' : '6';
    }
};

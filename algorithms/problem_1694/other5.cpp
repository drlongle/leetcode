class Solution {
public:
    string reformatNumber(const string& number) {
        string s;
        for(auto i:number)
            if(isdigit(i)) s+=i;

        int dash=s.size()/3, last=s.size()%3;
        if(!last) --dash;
        auto it=s.begin()+3;
        while(dash--) {
            it=s.insert(it,'-');
            it+=4;
        }

        if(last==1)
            swap(*(s.end()-2),*(s.end()-3));

        return s;
    }
};

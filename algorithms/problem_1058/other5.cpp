class Solution {
public:

    string minimizeError(vector<string>& prices, int target) {
        int n= prices.size();
        vector<double> m;
        int fsum=0;
        for(auto i: prices){
            double f= stod(i);
            double ff= floor(f);
            m.push_back({ceil(f)-f});
            fsum+=ff;
        }
        if(fsum>target|| target>fsum+n) return "-1";
        sort(m.begin(),m.end());

        double ret=0.0;
        int i=0;
        while(fsum!=target&&i<m.size())
        {
            if(m[i]!=0){
                ret+=m[i];
                fsum++;
            }
            i++;
        }
        if(fsum!=target) return "-1";

        for(i;i<m.size();i++){
            if(m[i] == 0) continue;
            cout << 1-m[i];
            ret+=1-m[i];

        }
        string s= to_string(ret);

        i = 0;
        for(i; i< s.size(); i++){
            if(s[i] == '.') break;
        }
        return s.substr(0,i+4);
    }
};

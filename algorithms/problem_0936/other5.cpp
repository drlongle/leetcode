class Solution {
public:

    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        vector<string> stamps;
        int sSize = stamp.size();
        int tSize = target.size();
        for(int i=0; i<sSize; i++){
            string tmp1 = string(i, '?') + stamp.substr(i, sSize - i);
            for(int j = sSize; j>i; j--){
                string tmp2 = tmp1.substr(0, j) + string(sSize - j, '?');
                stamps.push_back(tmp2);
            }
        }
        int flag = 1;
        int sSize2 = stamps.size();
        while(flag){
            flag = 0;
            for(int i=0; i<sSize2; i++){
                auto pos = target.find(stamps[i]);
                while(pos != target.npos){
                    int ps = pos;
                    flag = 1;
                    res.push_back(ps);
                    for(int j=0; j<sSize; j++){
                        target[j+ps] = '?';
                    }
                    pos = target.find(stamps[i]);
                }
            }
        }
        if(target == string(tSize, '?')){
            reverse(res.begin(), res.end());
            return res;
        }
        return {};
    }
};

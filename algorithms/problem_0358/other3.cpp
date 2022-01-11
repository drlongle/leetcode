class Solution {
public:
    string rearrangeString(string s, int k) {
        // frequencies of the characters
        vector<int>freq(26, 0);
        for(char c: s){
            freq[c-'a']++;
        }
        // max frequency
        priority_queue<pair<int,char>>pq;

        int f_max = 0;
        for(int i=0;i<26;i++){
            f_max=max(freq[i],f_max);
            if(freq[i]>0){
                pq.push(make_pair(freq[i],'a'+i));
            }
        }
        // count the most frequent characters
        int n_max = 0;
        for(int i=0;i<26;i++){
            if(f_max == freq[i])
                n_max++;
        }

        int cal_gap = (f_max-1) * (k) + n_max;
        int newLen =  max(int(s.length()),cal_gap);
        if(newLen != s.length())
            return "";

        string res = "";
        int idx = 0;int count=0;
        queue<pair<int,char>>q;

        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            res +=  p.second;
            q.push({p.first - 1, p.second});
            if (q.size() >= k) {
                auto p = q.front(); q.pop();
                if (p.first)
                    pq.push({p.first, p.second});
            }
        }
        return res;
    }
};

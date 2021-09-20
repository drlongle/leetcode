class Solution {
public:
    string rearrangeString(string s, int k) {

        //Base Case
        if(k <= 1) return s;

        unordered_map<char, int> count;
        for(auto c : s) count[c]++;

        priority_queue<pair<int, char>> pq;

        // Build Priority queue
        for(auto i : count) pq.push({i.second, i.first});
        string res;

        while(!pq.empty())
        {
            vector<pair<int, char>> cache;
            // Round of k
            for(int i = 0; i < k; i++)
            {
                // At least k distance condition will fail if not sufficient elements
                if(pq.empty()) return "";

                auto tmp = pq.top();
                pq.pop();

                // Build the res
                res.push_back(tmp.second);

                // We successfully got our ans
                if(res.size() == s.size()) return res;

                //Placed one char decrease the count of current char and push in our cache (Note : we are not pushing directly
                //to the queue otherwise if this current char comes again at the top of queue it will violate our condition)
                if(--tmp.first > 0)
                    cache.push_back(tmp);
            }

            for(auto i : cache) pq.push(i);
        }

        // Empty string case
        return "";
    }
};

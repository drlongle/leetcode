class Solution {
public:
    string sortString(string s) {
        string t;
		priority_queue<char, vector<char>, greater<char>> pq1(s.begin(), s.end());
        priority_queue<char> pq2;
        
        while (!pq1.empty() || !pq2.empty()) {
            bool isFirst(true);
            while (!pq1.empty()) {
                if (isFirst) {
                    t += pq1.top();
                    isFirst = false;
                } else if (t.back() < pq1.top()) t += pq1.top();
                else pq2.push(pq1.top());
                pq1.pop();
            }
            isFirst = true;
            while (!pq2.empty()) {
                if (isFirst) {
                    t += pq2.top();
                    isFirst = false;
                } else if (t.back() > pq2.top()) t += pq2.top();
                else pq1.push(pq2.top());
                pq2.pop();
            }
        }
        return t;
    }
};

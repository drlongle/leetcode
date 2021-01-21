class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string host = startUrl.substr(0, startUrl.find('/', 7));
        unordered_set<string> visited{startUrl};
        queue<string> q;
        q.push(startUrl);
        while(q.size())
        {
            auto s = q.front(); q.pop();
            auto lst = htmlParser.getUrls(s);
            for(auto& u : lst)
            {
                if(!visited.count(u) && u.compare(0, host.length(), host) == 0)
                {
                    q.push(u);
                    visited.insert(u);
                }
            }
        }
        return {visited.begin(), visited.end()};
    }
};

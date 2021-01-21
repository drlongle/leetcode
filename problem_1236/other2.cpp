class Solution {
public:
    vector<string> res;
    bool isValid(string org, string link) {
        if(org == link) return true;
        if(org.size() > link.size()) return false;
        for(int i = 0; i < org.size(); i++) {
            if(link[i] != org[i]) return false;
        }
        return true;
    }
    void DFS(string start, string org, HtmlParser htmlParser,
             unordered_set<string> &visited) {
        visited.insert(start);
        res.push_back(start);
        for(auto &link : htmlParser.getUrls(start)) {
            if(!visited.count(link) and isValid(org, link))
                DFS(link, org, htmlParser, visited);
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> visited;
        int last = startUrl.find('/', 7);
        string org = startUrl.substr(0, last);
        DFS(startUrl, org ,htmlParser, visited);
        return res;
    }
};

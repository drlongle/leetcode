class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        std::unordered_set<string> res;
        std::string prefix{getHost(startUrl)};
        res.insert(startUrl);
        std::vector<string> urls{htmlParser.getUrls(startUrl)}, other;
        while(!urls.empty()) {
            for(const auto &url: urls) {
                if(url.rfind(prefix, 0) != 0) continue;
                if(res.count(url)) continue;
                res.insert(url);
                auto next = htmlParser.getUrls(url);
                for(const auto &url: next) if(!res.count(url)) other.emplace_back(url);
            }
            swap(urls, other);
            other.clear();
        }
        return std::vector<string>(res.begin(), res.end());
    }

    std::string getHost(std::string url) {
        int i{0}, j = url.find('/');
        for(int k{0}; k < 2; ++k) i = j, j = url.find('/', j+1);
        return url.substr(0, j);
    }
};

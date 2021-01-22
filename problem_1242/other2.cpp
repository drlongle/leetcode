class Solution {
public:
    vector<string> crawl(const string &startUrl, HtmlParser htmlParser) {
        set_visited(startUrl);

        vector<string> urls = htmlParser.getUrls(startUrl);

        /* Remove URLs that doesn't belong to startURL domain */
        urls.erase(
                remove_if(urls.begin(), urls.end(), [&] (const string &url) {
                    return get_domain(startUrl) != get_domain(url);
                }), urls.end());

        vector<future<vector<string>>> futures;

        for (const auto &url : urls) {
            if (!is_visited(url)) {
                set_visited(url);

                /* Start an async task for new crawl job */
                auto worker_future = async(launch::async, [=] () {
                    return crawl(url, htmlParser);
                });
                futures.push_back(move(worker_future));
            }
        }

        /* Collect results from started tasks */
        vector<string> out = collect_results(futures);
        out.push_back(startUrl);
        return out;
    }

private:
    vector<string> collect_results(vector<future<vector<string>>> &futures) const {
        vector<string> out;
        for (auto &worker_future : futures) {
            const auto future_result = worker_future.get();
            out.insert(out.end(),
                       future_result.begin(),
                       future_result.end());
        }
        return out;
    }

    bool is_visited(const string &url) const {
        unique_lock<mutex> lock(visited_lock);
        return visited.count(url) != 0;
    }

    void set_visited(const string &url) {
        unique_lock<mutex> lock(visited_lock);
        visited.insert(url);
    }

    string get_domain(const string& url) const {
        auto end = url.find("/", 7);
        return url.substr(0, end);
    }

    set<string> visited;
    mutable mutex visited_lock;
};

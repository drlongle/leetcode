class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(startUrl);
        string host = hostName(move(startUrl));

        auto process = [&](){
            while (true) {
                unique_lock ulk(m_mtx_pop);
                if (q.empty()) {
                    return;
                }
                string top = move(q.front());
                q.pop();
                if (visited.count(top) != 0 || hostName(top) != host) {
                    continue;
                }
                visited.insert(top);
                ulk.unlock();

                vector<string> urls = htmlParser.getUrls(move(top));
                for (string& url: urls) {
                    lock_guard lkg(m_mtx_push);
                    q.push(move(url));
                }
            }
        };

        vector<thread> workers;
        for (int i = 0; i < NUM_THREADS; ++i) {
            workers.emplace_back(process);
        }

        for_each(workers.begin(), workers.end(), [](thread& t) {
            t.join();
        });

        return {visited.begin(), visited.end()};
    }

private:
    static constexpr int NUM_THREADS{4};

    mutex m_mtx_push;
    mutex m_mtx_pop;

    string hostName(string url) {
        replace(url.begin(), url.end(), '/', ' ');
        istringstream iss(url);
        iss >> url >> url;
        return move(url);
    }
};

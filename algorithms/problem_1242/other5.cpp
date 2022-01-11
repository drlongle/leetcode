#define NUM_THREADS 8
class Solution {
private:
    mutex mtx_push;
    mutex mtx_pop;
public:

    string hostName(string& s) {
        int n = s.find('/', 7);
        n = n == string::npos?s.length():n - 7;
        return s.substr(7, n);
    }

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {

        unordered_set<string> visited;
        queue<string> q;

        q.push(startUrl);

        string host = hostName(startUrl);

        function<void()> process = [&]() -> void {
            while(true) {
                mtx_pop.lock();
                if (q.empty()) {
                    mtx_pop.unlock();
                    return;
                }
                string top = q.front();
                q.pop();

                string topHostName = hostName(top);

                if (topHostName != host || visited.find(top) != visited.end()) {
                    mtx_pop.unlock();
                    continue;
                }
                visited.insert(top);
                mtx_pop.unlock();
                vector<string> urls = htmlParser.getUrls(top);
                for (string url : urls) {
                    mtx_push.lock();
                    q.push(url);
                    mtx_push.unlock();
                }

            }
        };

        vector<thread> workers;
        for (int i = 0; i < NUM_THREADS; ++i) {
            workers.push_back(thread(process));
        }

        for_each(workers.begin(), workers.end(), [](thread& t) {
            t.join();
        });

        return vector<string>(visited.begin(), visited.end());

    }
};
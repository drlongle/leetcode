class Solution {
    string get_host(string url) {
        string str;
        stringstream ss(url);
        getline(ss, str, '/');
        getline(ss, str, '/');
        getline(ss, str, '/');
        return str;
    }

public:

    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> que;
        que.push(startUrl);
        unordered_set<string> visited{startUrl};
        auto host0 = get_host(startUrl);
        mutex mtx;
        condition_variable cv;

        int num_thread = 4;

        auto worker = [&]() {
            while (true) {
                unique_lock<mutex> lk1(mtx);

                cv.wait_for(lk1, 30ms, [&](){ return que.size(); });

                if (que.empty()) {
                    return;
                }

                auto cur = que.front();
                que.pop();

                lk1.unlock();

                auto res = htmlParser.getUrls(cur);

                lk1.lock();
                for (auto ne : res) {
                    if (get_host(ne) == host0 && !visited.count(ne)) {
                        visited.insert(ne);
                        que.push(ne);
                    }
                }
                lk1.unlock();
                cv.notify_all();
            }
        };

        vector<thread> workers;
        for (int i = 0; i < num_thread; i++) {
            workers.emplace_back(worker);
        }
        for (auto &w : workers) {
            w.join();
        }

        return {visited.begin(), visited.end()};
    }
};

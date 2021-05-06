class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            q.push({v1.begin(), v1.end()});
        }
        if (!v2.empty()) {
            q.push({v2.begin(), v2.end()});
        }
    }

    int next() {
        auto front = q.front().first;
        auto end = q.front().second;
        q.pop();
        int val = *front;
        ++front;
        if (front != end) {
            q.push({front, end});
        }
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
private:
    using v_it = std::vector<int>::iterator;
    std::queue<std::pair<v_it, v_it>> q;
};

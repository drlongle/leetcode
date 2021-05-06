class ZigzagIterator {
private:
    vector<int>V;
    queue<pair<int,int>>Iterators;
    const int INVALID_VAL;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : INVALID_VAL(-1) {
        int len1 = v1.size();
        int len2 = v2.size();

        if (len1 != 0) {
            V.insert(V.begin(), v1.begin(), v1.end());
            Iterators.push({0, len1});
        }

        if (len2 != 0) {
            V.insert(V.end(), v2.begin(), v2.end());
            Iterators.push({len1, len1+len2});
        }
    }

    int next() {
        if (!hasNext()) return INVALID_VAL;

        pair<int, int>iterator = Iterators.front();
        Iterators.pop();

        int val = V[iterator.first++];
        if (iterator.first < iterator.second) Iterators.push(iterator);

        return val;
    }

    bool hasNext() {
        return !Iterators.empty();
    }
};

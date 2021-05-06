class ZigzagIterator {
private:
    queue<pair<vector<int>&, int> > vectorsQueue;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        if(v1.size() > 0) vectorsQueue.push({v1,0});
        if(v2.size() > 0) vectorsQueue.push({v2,0});
    }

    int next() {
        int ans = 0;

        pair<vector<int>&, int> current = vectorsQueue.front();
        vectorsQueue.pop();
        vector<int> &v = current.first;
        int index = current.second;

        if(index < v.size()) ans = v[index];
        index++;
        if(index < v.size()) vectorsQueue.push({v,index});

        return ans;
    }

    bool hasNext() {
        return !vectorsQueue.empty();
    }
}

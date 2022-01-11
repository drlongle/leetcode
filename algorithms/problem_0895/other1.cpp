class FreqStack {
public:
    unordered_map<int, int> mp;
    unordered_map<int, stack<int>> mst;
    int maxf=0;

    void push(int x) {
        mp[x]++;
        maxf = max(maxf, mp[x]);
        mst[mp[x]].push(x);
    }

    int pop() {
        int top = mst[maxf].top();
        mst[maxf].pop();
        mp[top]--;
        if(mst[maxf].size()==0) {
            mst.erase(maxf);
            maxf--;
        }
        return top;
    }
};

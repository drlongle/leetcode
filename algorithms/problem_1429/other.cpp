class FirstUnique {
public:
    queue<int> qu;                     // To keep the order of elements maintained
    unordered_map<int, int> freq;      // To keep the frequency of each element
    FirstUnique(vector<int>& nums) {
        for (auto num: nums) qu.push(num), freq[num]++;
    }
    
    int showFirstUnique() {
        while(!qu.empty() && freq[qu.front()] > 1) {
            qu.pop();
        }
        if(qu.empty()) return -1;
        else return qu.front();
    }
    
    void add(int value) {
        qu.push(value);
        freq[value]++;
    }
};

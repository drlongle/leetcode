class MyCalendarTwo {
public:
    map<int,int> cur;
    MyCalendarTwo() {
        cur.clear();
    }
    bool book(int start, int end) {
        cur[start]++; cur[end]--;
        int sum = 0, maxc = 0;
        for (auto it=cur.begin(); it!=cur.end() && it->first<end; it++){
            sum += it->second;
            maxc = max(maxc, sum);
        }
        if(maxc>2){
            cur[start]--;
            cur[end]++;
            return false;
        }
        return true;
    }
};

class MyCalendarThree {
public:
    map<int,int> m;
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int count=0;
        int scount=0;
        for(auto i=m.begin();i!=m.end();i++){
            scount+=i->second;
            count=max(count,scount);

        }
        return count;

    }
};

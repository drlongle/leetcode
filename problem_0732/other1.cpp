class MyCalendarThree {
public:
    map<int,int> pref;

    MyCalendarThree() {
        pref.clear();
    }

    int book(int start, int end) {
        pref[start]++;
        pref[end]--;
        int ans = 0;
        int cnt = 0;
        for(auto &x : pref){
            cnt+=x.second;
            ans = max(ans , cnt) ;
        }

        return ans;
    }
};


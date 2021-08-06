class Solution {
public:
    // Set char value to next present greater or min to simulate overflow
    bool UpdateToNext(const set<char>& m, char& c, char max)
    {
        auto it{ m.upper_bound(c) };
        if (it != m.end() && *it <= max)
        {
            c = *it;
            return true;
        }

        c = *m.begin();
        return false;
    }

    string nextClosestTime(string time)
    {
        set<char> m;
        for (size_t i : { 0, 1, 3, 4 })
            m.insert(time[i]);

        if (UpdateToNext(m, time[4], '9')) // update mins2
            return time;

        if (UpdateToNext(m, time[3], '5'))// update mins1
            return time;

        if (UpdateToNext(m, time[1], time[0] == '2'? '3' : '9')) // update hours2
            return time;

        UpdateToNext(m, time[0], '2'); // update hours1
        return time;
    }
};

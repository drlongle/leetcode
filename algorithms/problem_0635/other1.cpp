class LogSystem
{
    multimap<string, int> logs;
    unordered_map<string, int> gran_map;

    inline static const string PowerTime = "9999:12:31:59:59:59";
public:
    LogSystem()
    {
        gran_map.emplace("Year", 4);
        gran_map.emplace("Month", 7);
        gran_map.emplace("Day", 10);
        gran_map.emplace("Hour", 13);
        gran_map.emplace("Minute", 16);
        gran_map.emplace("Second", 19); // take all, no ':' at end
    }

    void put(int id, string timestamp)
    {
        logs.emplace(timestamp, id);
    }

    vector<int> retrieve(string s, string e, string gra)
    {
        string ef_start, ef_end;

        int take_till = gran_map[gra];

        if (take_till == 19)   // second?
        {
            ef_start = s;
            ef_end = e;
        }
        else
        {
            ef_start = s.substr(0, take_till);
            ef_end = e.substr(0, take_till) + PowerTime.substr(take_till);
        }

        auto lower = logs.lower_bound(ef_start);
        auto upper = logs.upper_bound(ef_end);

        vector<int> result;
        while (lower != upper)
        {
            result.push_back(lower->second);
            ++lower;
        }

        return result;
    }
};

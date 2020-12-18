class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, bool>> bounds; // time and flag: start=true/end=false
        for (const auto& r : intervals)
        {
            bounds.emplace_back(r[0], true);
            bounds.emplace_back(r[1], false);
        }

        // sort bounds lexicographically. on equivalnce of first (time), the priority
        // is of ending bound (second = false) -- this is too free room immediately before
        // busy with next meeting.
        sort(bounds.begin(), bounds.end());

        int maxongoing{};
        int currongoing{};
        for (auto b : bounds)
        {
            currongoing += b.second ? 1 : -1;
            maxongoing = max(maxongoing, currongoing);
        }

        return maxongoing;
    }
};


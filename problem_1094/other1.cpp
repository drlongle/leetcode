class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        vector<pair<bool, vector<int>*>> inOut;

        for (auto& trip : trips) {
            inOut.emplace_back(true, &trip);
            inOut.emplace_back(false, &trip);
        }

        sort(inOut.begin(), inOut.end(), [](auto& l, auto& r) {
            int lDis = l.first ? (*l.second)[1] : (*l.second)[2];
            int rDis = r.first ? (*r.second)[1] : (*r.second)[2];

            return lDis < rDis || (lDis == rDis && l.first == false && r.first == true);
        });

        for (pair<bool, vector<int>*>& trip : inOut) {
            if (trip.first)
                capacity -= (*trip.second)[0];
            else
                capacity += (*trip.second)[0];
            if (capacity < 0)
                return false;
        }
        return true;
    }
};

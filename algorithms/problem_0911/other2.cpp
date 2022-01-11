class TopVotedCandidate {
private:
    map<int, int> map1;
    pair<int, int> previousOne = {0, 0};
    unordered_map<int, int> hashMap;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        for (int i = 0; i < persons.size(); ++i) {
            ++hashMap[persons[i]];

            map1[times[i]] = hashMap[persons[i]] > previousOne.second ? persons[i] : previousOne.first;
            if (previousOne.second > hashMap[persons[i]]) {
                map1[times[i]] = previousOne.first;
            } else {
                map1[times[i]] = persons[i];
                previousOne = {persons[i], hashMap[persons[i]]};
            }
        }
    }

    int q(int t) {
        if (map1.count(t)) {
            return map1[t];
        } else {
            map<int, int>::iterator it = map1.lower_bound(t);
            --it;
            return it->second;
        }
    }
};

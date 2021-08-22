/*
Use a HashMap to map index of a land to its island_ID (starting from 0). For each addLand operation at
position (row, col), check if its adjacent neighbors are in the HashMap or not and put the island_ID of
identified neighbors into a set (where each element is unique):

- if the set is empty, then the new land at position (row, col) forms a new island (monotonically increasing island_ID by 1);

- if the set contains only one island_ID, then the new land belongs to an existing island and island_ID remains unchanged;

- if the set contains more than one island_ID, then the new land bridges these separate islands into one island,
  we need to iterate through the HashMap to update this information (time consuming!) and decrease the number of island
  appropriately.
*/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;
        unordered_map<int, int> land2id; // land index : island ID
        int num_islands = 0;
        int island_id = 0;
        for (auto pos : positions) {
            int r = pos.first;
            int c = pos.second;
            // check pos's neighbors to see if they are in the existing islands or not
            unordered_set<int> overlap; // how many existing islands overlap with 'pos'
            if (r - 1 >= 0 && land2id.count((r-1) * n + c)) overlap.insert(land2id[(r-1) * n + c]);
            if (r + 1 < m && land2id.count((r+1) * n + c)) overlap.insert(land2id[(r+1) * n + c]);
            if (c - 1 >= 0 && land2id.count(r * n + c - 1)) overlap.insert(land2id[r * n + c - 1]);
            if (c + 1 < n && land2id.count(r * n + c + 1)) overlap.insert(land2id[r * n + c + 1]);

            if (overlap.empty()) { // no overlap
                ++num_islands;
                land2id[r * n + c] = island_id++; // new island
            } else if (overlap.size() == 1) { // one overlap, just append
                auto it = overlap.begin();
                land2id[r * n + c] = *it;
            } else { // more than 1 overlaps, merge
                auto it = overlap.begin();
                int root_id = *it;
                for (auto& kv : land2id) { // update island id
                    if (overlap.count(kv.second)) kv.second = root_id;
                }
                land2id[r * n + c] = root_id;
                num_islands -= (overlap.size() - 1);
            }

            ans.push_back(num_islands);
        }

        return ans;
    }
};
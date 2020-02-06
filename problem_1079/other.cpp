class Solution {
public:
    unordered_set<string> seq;
    int numTilePossibilities(string tiles) {
        helper(tiles, "", tiles.size());
        return seq.size();
    }
    void helper(string tiles, string pos, int entry) {
        if(entry <0) return;
        if(!pos.empty())
            seq.insert(pos);
        for(int i=0; i< tiles.size(); i++)
            helper(tiles.substr(0, i)+tiles.substr(i+1), pos+tiles[i], entry-1);
    }
};

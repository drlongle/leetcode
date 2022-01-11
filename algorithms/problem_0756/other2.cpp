class Solution {
public:
    bool  result = false;
    bool helper(const string &level, const int begin, const unordered_map<string, vector<string>> &mymap, string nextlevel)
    {
        if(begin == level.size() -1){
            //reached the end of current level.
            if(nextlevel.size() == 1) {
                // you reached the end of current level , and nextlevel size is 1, meaning top of the pyramid
                result = true;
                return true;
            }
            //make nextlevel as current level and continue;
            string nextnextlevel;
            return helper(nextlevel, 0, mymap, nextnextlevel);
        }
        bool rc = false;
        auto leaves = level.substr(begin, 2);//get leaves string
        auto mit = mymap.find(leaves);
        if(mit == mymap.end())
            return false;
        for(const auto &parent:mit->second){
            // for every parent which these leaves can map to, add the parent to nextlevel
            auto tsize = nextlevel.size();
            nextlevel.append(parent);
            rc |= helper(level, begin+1, mymap, nextlevel);
            nextlevel.erase(tsize);
            //if somewhere during backtracking recursion, there was solution found, break;
            if(result)
                break;
        }
        return rc;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // build map of leaves to parent combinations.
        // leaves are the first 2 chars in the allowed string.
        // parent is the last char in the allowed string.
        unordered_map<string, vector<string>> mymap;
        for(const auto & a: allowed){
            mymap[a.substr(0,2)].push_back(a.substr(2,1));
        }
        string running;
        helper(bottom , 0, mymap, running);
        return result;
    }
};

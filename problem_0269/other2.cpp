class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> hmap; //adjList
        map<char, int> indMap; //in-degree map
        string output = "";

        //initiate in-degree map for all characters to 0
        for (auto word : words)
            for (auto ch : word)
                if (indMap.find(ch) == indMap.end())
                    indMap[ch] = 0;

        //build the adj-list and update the in-degree when adj-list is updated
        for (int i = 0; i < words.size() -1; i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];

            //edge case w1="xyza"  and w2="xy"
            if (w1.length() > w2.length() && w1.find(w2) == 0)
                return "";

            for (int j = 0; j < std::min(w1.length(), w2.length()); j++)
            {
                if (w1[j] == w2[j])
                    continue;

                if (std::find(hmap[w1[j]].begin(), hmap[w1[j]].end(), w2[j]) == hmap[w1[j]].end())
                {
                    hmap[w1[j]].push_back(w2[j]);

                    //update the in-degree map
                    indMap[w2[j]] +=1;
                }
                break;
            }
        }

        //topological sort
        queue<char> q;

        //add all 0 degree indices to the queue
        for (auto ind : indMap)
            if (ind.second == 0)
                q.push(ind.first);

        while (!q.empty())
        {
            char node = q.front();
            q.pop();

            output = output + node;
            for (auto nbr : hmap[node])
            {
                //update in-degree for the neighbor nodes
                indMap[nbr] -= 1;
                if (indMap[nbr] == 0)
                    q.push(nbr);
            }
        }

        if (output.size() != indMap.size())
            return "";

        return output;
    }
};

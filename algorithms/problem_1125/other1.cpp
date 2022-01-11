/*
1, Enumerate given skills. Their index will act as index of bit when we do bitmasking. Also create a set to store diff combination of skills (bitwise).
2. for each people :
2.1 calculate bitmask of all its skill
for each prev bitmask in our set:
2.1.1 calculate combo of prev and curr skill
2.1.2 if combo doesn't exist already , add it with this people id
2.1.3 if combo bitmask exists but with a larger group of people, replace it with current people and group of people with prev bitmask
3. return group of people with bitmask (1<<(skills.size())) -1.

Note: The i-th skill is represented by the bit (1 << i). Given n = req_skills.ize(), the bitmask ((1<<n) - 1) represents all the required skills.
*/

vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people)
{
    int n = req_skills.size();
    map<int,vector<int>> res;
    res[0]={};
    unordered_map<string,int> skill_map;
    for(int i=0;i< req_skills.size();i++)
        skill_map[req_skills[i]]=i;

    for(int i=0;i<people.size();i++)
        {
            int curr_skill = 0;
            for(int j=0;j<people[i].size();j++)
                curr_skill |= 1<<skill_map[people[i][j]];
            
            for(auto it = res.begin();it!=res.end();it++)
                {
                    int comb = it->first | curr_skill;
                    if(res.find(comb)==res.end() || res[comb].size()>1+res[it->first].size())
                        {
                            res[comb]=it->second;
                            res[comb].push_back(i);
                        }       
                }
        }
    return res[(1<<n) -1];
}

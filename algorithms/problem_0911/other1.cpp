class TopVotedCandidate {
public:
    vector<pair<int,int>> vec;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int counter[persons.size()+1]={0};
        int maxsofar = 1;
        int maxvote = persons[0];
        counter[maxvote]++;
        vec.push_back({times[0],maxvote});
        for(int i=1;i<persons.size();i++)
        {
            counter[persons[i]]++;
            if(maxsofar <= counter[persons[i]])
            {
                maxsofar = counter[persons[i]];
                maxvote = persons[i];
            }
            vec.push_back({times[i],maxvote});
        }
    }
    
    int q(int t) {
        int low=0,high=vec.size()-1;
        int ans;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(vec[mid].first < t)
            {
                ans=vec[mid].second;
                low=mid+1;
            }
            else if(vec[mid].first > t)
                high = mid-1;
            else
                return vec[mid].second;
        }
        return ans;
    }
};

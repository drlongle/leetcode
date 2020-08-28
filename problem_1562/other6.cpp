class Solution {
public:
    //Basic union find related storages (groupCounts stores # of groups of size `i`- our reverse mapping)
    vector<int> parent,Rank,count,groupCounts;
    int Find(int x)
    {
        return parent[x]==x?x:parent[x]=Find(parent[x]);
    }
    void Union(int x,int y)			//Modified union to update groupCounts
    {
        int xset=Find(x),yset=Find(y);
        if(xset!=yset)
        {
            groupCounts[count[xset]]--,groupCounts[count[yset]]--;//Union'ing would change the groupSize of current x and y groups.
            count[xset]=count[yset]=count[xset]+count[yset];		//Size of groups of x and y now are now size(x)+size(y)
            groupCounts[count[xset]]++;
            Rank[xset]<Rank[yset]?parent[xset]=yset:parent[yset]=xset;
            if(Rank[xset]==Rank[yset])
                Rank[xset]++;
        }
    }
    int findLatestStep(vector<int>& arr, int m)
    {
        parent.resize(arr.size()+1),Rank.resize(arr.size()+1,0);			//Few lines for basic initialization.
        for(int i=1;i<=arr.size();i++)
            parent[i]=i;
        vector<bool> visited(arr.size()+1,false);
        count.resize(arr.size()+1,1);			//Currently all groups are of size 1
        groupCounts.resize(arr.size()+1,0);
        int last=-1,step=1;						//Last stores the result, step is the current step (We can move this to a for loop)
        for(int &i:arr)
        {
            groupCounts[1]++;					//We always chose a new number whose current groupSize is 1 so we increase the groupCount[1] (Reverse Map)
            if(i+1<=arr.size()&&visited[i+1])	//Union i and i+1 if i+1'th bit was previously set
                Union(i,i+1);
            if(i-1>0&&visited[i-1])				//Union i and i-1 if i-1'th bit was previously set
                Union(i,i-1);
            visited[i]=true;
            if(groupCounts[m])					//If counts of group of size m is > 0 (This means we have a group of size m at current step, update `last`)
                last=step;
            step++;
        }
        return last;
    }
};

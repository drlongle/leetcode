class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   ector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        queue<int> q;
        int result=0;
        //Only used to store boxes that are reached but closed.
        vector<bool> reachableClosedBoxes(status.size(),false);
        //Push initial boxes that we can open in the queue.
        for(int &i:initialBoxes)
            if(status[i])
                q.push(i);
            else
                reachableClosedBoxes[i]=true;
        //Continue until no more boxes are left that can be opened.
        while(!q.empty())
        {
            result+=candies[q.front()];	//Add candies we got.
            for(int &i:keys[q.front()])	//Open the box whose keys are found.
            {
                //If the box was previously closed and we already reached it,use it as an open box
                if(!status[i]&&reachableClosedBoxes[i])
                    q.push(i);
                status[i]=1;
            }
            //Push all the boxes within this box for then next cycle in the queue.
            for(int &i:containedBoxes[q.front()])
                if(status[i])
                    q.push(i);
                else
                    reachableClosedBoxes[i]=true; //The box is closed, wait until we get the keys for this box.
            q.pop();
        }
        return result;
    }
};

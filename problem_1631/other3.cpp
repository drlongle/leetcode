class Solution {
public:

    // min heap comparator
    struct comparator {
        bool operator()(vector<int> const& a, vector<int> const& b)
        {
            return a[2] > b[2];
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {

        // min heap contains <x,y,cost> based on minimum cost
        priority_queue<vector<int>, vector<vector<int>>, comparator> Q;

        int m = heights.size();
        int n = heights[0].size();

        // track the cost of the location <x,y>
        vector<vector<int>>hikeCost(m,vector<int>(n,INT_MAX));

        // push start location [0,0] and cost 0
        Q.push({0,0,0});

        // set initial position cost 0
        hikeCost[0][0] = 0;

        int cx,cy,tx,ty,tcost,cost;
        int rowOffest[] = {0,0,1,-1};
        int colOffest[] = {1,-1,0,0};

        // loop until all nodes processed or destination is reached
        while(!Q.empty())
        {
            vector<int>node = Q.top();
            Q.pop();

            cx = node[0];
            cy = node[1];
            cost = node[2];

            // destination reached so current cost is the minimum effort and so return
            if(cx==m-1 && cy==n-1)
                return cost;

            // if current cost is grater than existing cost of the node position then continue or ignore
            // cause we want to find the path of minimum effort
            if(hikeCost[cx][cy]<cost)continue;

            // generate neighbour nodes
            for(int i=0;i<4;i++)
            {
                tx = cx + rowOffest[i];
                ty = cy + colOffest[i];

                // check neighbour node is in grid range
                if(tx<m && tx>=0 && ty<n && ty>=0)
                {
                    // neighbour node cost = max(current cost, absolute difference between current and neighbour height)
                    // taking max cause effort is the max absolute difference between any two consecutive element of the path
                    tcost = max(cost,abs(heights[cx][cy]-heights[tx][ty]));

                    // neighbour node cost is less than its existing cost then we will update and push in to queue
                    // cause we want to find the path with minimum effort
                    // this also eliminates the parent node of the current node
                    if(tcost<hikeCost[tx][ty])
                    {
                        hikeCost[tx][ty] = tcost;
                        Q.push({tx,ty,tcost});
                    }
                }
            }
        }

        return 0;
    }
};

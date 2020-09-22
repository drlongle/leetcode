// Prim's algorithm
// mindis[i] is the minimum distance from the current chunk to city i if i has not been connected
class Solution {
    int d(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        static bool connected[1000];
        static int mindis[1000];
        int size=points.size();
        int i;
        int ans=0;
        int Min, Minindex;
        int newpoint=0;
        int connectedsize=1;
        connected[0]=true;
        for(i=1;i<size;i++){
            connected[i]=false;
            mindis[i]=INT_MAX;
        }
        while(connectedsize<size){
            Min=INT_MAX;
            for(i=1;i<size;i++){
                if(!connected[i]){
                    mindis[i]=min(d(points[newpoint], points[i]), mindis[i]);
                    if(Min>mindis[i]){
                        Min=mindis[i];
                        Minindex=i;
                    }
                }
            }
            ans+=Min;
            newpoint=Minindex;
            connected[newpoint]=true;
            connectedsize++;
        }
        return ans;
    }
};

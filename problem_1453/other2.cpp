/*
Angular sweep

This is the "disk partial covering problem" in the literature, which can be solved with angular sweep. Search "angular sweep" at Geeksforgeeks for more details.(Leetcode does not allow me to post the link.)

The basic idea is: for each point, place it on the circle boundary. Then sweep (or "rotate") the circle around this point to see which direction contains the most points. Do this for all points and we find the global max.

The sweep around a point p can be done in O(nlogn) time by: (a) for another point q != p, find the entering angle such that when we place the circle at this angle, this circle contains q (i.e., q enters the circle); (b) similarly, find the exit angle such that when we further increase the angle, the point q will not be inside the circle anymore; and (c) sort the angles so that we can march/sweep around all other points in linear time.

Therefore, it takes O(nlogn) time to find the best circle for a fixed anchor point p, and then multiply that by O(n) to perform the check for all points. The total time is O(n^2 log n).

https://www.geeksforgeeks.org/angular-sweep-maximum-points-can-enclosed-circle-given-radius/
 */

class Solution {
public:
    int numPoints(vector<vector<int>>& p, int r) {
        int n = p.size();
        vector<vector<double>> dist(n, vector<double>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                dist[i][j] = dist[j][i] = sqrt((p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]));
            }
        }
        
        int res = 1;
        for (int i=0; i<n; ++i) {
            vector<pair<double, bool>> angles;
            
            for (int j=0; j<n; ++j) {
                if (j != i && dist[i][j] <= 2 * r) {
                    double A = atan2(p[j][1] - p[i][1], p[j][0] - p[i][0]);
                    double B = acos(dist[i][j] / (2.0 * r));
                    double alpha = A-B; 
                    double beta = A+B; 
                    angles.push_back(make_pair(alpha, false)); // "false" means this point is entering
                    angles.push_back(make_pair(beta, true)); // "true" means this point is exiting
                }
            }
            
            sort(angles.begin(), angles.end());  // sort the angles
            
            int cnt = 1;
            for (auto it=angles.begin(); it!=angles.end(); ++it) 
            { 
                if ((*it).second == false) cnt++;   // if the point is entering, then increment
                else cnt--; // if it is exiting, then decrement

                res = max(res, cnt);
            } 
        }
        return res;
    }
};

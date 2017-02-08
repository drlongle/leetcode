/*
447. Number of Boomerangs

    User Accepted: 379
    User Tried: 624
    Total Accepted: 385
    Total Submissions: 1711
    Difficulty: Easy

Given n points in the plane that are all pairwise distinct, a "boomerang" is a
tuple of points (i, j, k) such that the distance between i and j equals the
distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and
coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 */

import java.io.*;
import java.util.*;

public class Solution {

    public int numberOfBoomerangs(int[][] points) {
        int res = 0;
        int numlen = points.length;
        
        int[][] distance = new int[numlen][numlen];
        for (int i = 0; i < numlen-1; ++i)
        {
            for (int j = i+1; j < numlen; ++j)
            {
                distance[i][j] =
                    (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) +
                    (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
            }
        }

        for (int i = 0; i < numlen-2; ++i)
        {
            for (int j = i+1; j < numlen-1; ++j)
            {
                int dist_ij = distance[i][j];
                for (int k = j+1; k < numlen; ++k)
                {
                    int dist_ik = distance[i][k];
                    int dist_jk = distance[j][k];
                    if (dist_ij == dist_ik)
                        res += 2;
                    if (dist_ij == dist_jk)
                        res += 2;
                    if (dist_ik == dist_jk)
                        res += 2;
                }
            }
        }
        
        return res;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] points;
        
        points = new int[][] {{0,0},{1,0},{2,0}};

        int res = sol.numberOfBoomerangs(points);
        System.out.println("Result: " + res);
    }
}

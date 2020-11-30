/*
218. The Skyline Problem

    Total Accepted: 25439
    Total Submissions: 104305
    Difficulty: Hard

https://leetcode.com/problems/the-skyline-problem/

A city's skyline is the outer contour of the silhouette formed by all the
buildings in that city when viewed from a distance. Now suppose you are given
the locations and height of all the buildings as shown on a cityscape photo
(Figure A), write a program to output the skyline formed by these buildings
collectively (Figure B).

The geometric information of each building is represented by a triplet of
integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and
right edge of the ith building, respectively, and Hi is its height. It is
guaranteed that 0 <= Li, Ri <= INT_MAX, 0 < Hi <= INT_MAX, and Ri - Li > 0. You
may assume all buildings are perfect rectangles grounded on an absolutely flat
surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as:
[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of
[ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key
 point is the left endpoint of a horizontal line segment. Note that the last
 key point, where the rightmost building ends, is merely used to mark the
 termination of the skyline, and always has zero height. Also, the ground in
 between any two adjacent buildings should be considered part of the skyline
 contour.

For instance, the skyline in Figure B should be represented as:
[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range
[0, 10000]. The input list is already sorted in ascending order by the left x
position Li. The output list must be sorted by the x position. There must be no
consecutive horizontal lines of equal height in the output skyline. For
instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the
three lines of height 5 should be merged into one in the final output as such:
[...[2 3], [4 5], [12 7], ...]
 */

import java.io.*;
import java.util.*;

public class Solution {
    class Point implements Comparable<Point>
    {
        public Point(int c, boolean s, int[] l)
        {
            coordinate = c;
            isStart = s;
            line = l;
        }
        
        public int compareTo(Point other)
        {
            if (coordinate < other.coordinate)
                return -1;
            else if (coordinate > other.coordinate)
                return 1;
            return 0;
        }
        
        public int coordinate;
        boolean isStart;
        int[] line;
    }

    public List<List<Integer>> getSkyline(int[][] buildings)
    {
        List<List<Integer>> result = new ArrayList<>();
        List<Point> points = new ArrayList<>();
        for (int i = 0; i < buildings.length; ++i)
        {
            int[] building = buildings[i];
            points.add(new Point(building[0], true, building));
            points.add(new Point(building[1], false, building));
        }

        Collections.sort(points);
        TreeMap<Integer, Set<int[]>> heightToLine = new TreeMap<>();
        Set<int[]> pointSet;
        int prevHigh = 0, currHigh;
        for (int i = 0; i < points.size(); ++i)
        {
            Point p = points.get(i);
            int coordinate;
            int pointHeight = p.line[2];
            if (p.isStart)
            {
                if (!heightToLine.containsKey(pointHeight))
                    heightToLine.put(pointHeight, new HashSet<int[]>());
                pointSet = heightToLine.get(pointHeight);
                pointSet.add(p.line);
                coordinate = p.line[0];
            }
            else
                coordinate = p.line[1];

            Map.Entry<Integer, Set<int[]>> highest = heightToLine.lastEntry();
            if (!p.isStart)
            {
                pointSet = heightToLine.get(pointHeight);
                pointSet.remove(p.line);
                if (pointSet.isEmpty())
                    heightToLine.remove(pointHeight);
            }

            highest = heightToLine.lastEntry();
            if (highest != null)
            {
                pointSet = highest.getValue();
                currHigh = highest.getKey();
            }
            else
            {
                pointSet = null;
                currHigh = 0;
            }

            if (prevHigh != currHigh)
            {
                while (result.size() > 0)
                {
                    List<Integer> lastPoint = result.get(result.size()-1);
                    if (lastPoint.get(0) != coordinate)
                        break;
                        if ((p.isStart && lastPoint.get(1) <= currHigh) ||
                            (!p.isStart && lastPoint.get(1) >= currHigh))
                            result.remove(result.size()-1); 
                }
                if (result.isEmpty() || result.get(result.size()-1).get(1) != currHigh)
                    result.add(Arrays.asList(new Integer[]{new Integer(coordinate), new Integer(currHigh)}));
            }
            prevHigh = currHigh;
        }
        
        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] buildings;

        //Expected: [[0,3],[7,0]] 
        buildings = new int[][]{{0,3,3},{1,5,3},{2,4,3},{3,7,3}};
        List<List<Integer>> result = sol.getSkyline(buildings);
        result.forEach(i -> System.out.println(i.get(0) + " " + i.get(1)));
    }
}

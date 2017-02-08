/*
207. Course Schedule

    Total Accepted: 53410
    Total Submissions: 183589
    Difficulty: Medium

There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to
first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it
possible for you to finish all courses?

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have
finished course 0. So it is possible.

2, [[1,0],[0,1]]

There are a total of 2 courses to take. To take course 1 you should have
finished course 0, and to take course 0 you should also have finished
course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not
adjacency matrices. Read more about how a graph is represented:
https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs
*/

import java.io.*;
import java.util.*;

public class Solution {
    public class Node
    {
        Node(int l)
        {
            label = l;
            edges = new ArrayList<>();
            status = 0;
        }

        List<Integer> edges;
        int label;
        int status;
    }

    List<Node> nodes = new ArrayList<>();
    public boolean dfs(int label)
    {
	Node node = nodes.get(label);
	if (node.status == 1)
	    return false;
	if (node.status == 2)
	    return true;
	node.status = 1; // Visiting
	for (Integer i: node.edges)
	    if (!dfs(i))
		return false;
	node.status = 2; // Done visiting!
	return true;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
	for (int i = 0; i < numCourses; ++i)
	    nodes.add(new Node(i));
	for (int[] pair: prerequisites)
	    nodes.get(pair[0]).edges.add(pair[1]);
	for (int i = 0; i < numCourses; ++i)
	{
	    if (!dfs(i))
		return false;
	}

        return true; 
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] prerequisites;
        int numCourses;
    
        numCourses = 2;
        prerequisites = new int[][] {{1,0}};
        System.out.println("Result: " +
            sol.canFinish(numCourses, prerequisites));
  }
}


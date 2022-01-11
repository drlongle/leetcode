/*
210. Course Schedule II

    Total Accepted: 37025
    Total Submissions: 159204
    Difficulty: Medium

There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the
ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them.
If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished
course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]

There are a total of 4 courses to take. To take course 3 you should have finished
both courses 1 and 2. Both courses 1 and 2 should be taken after you finished
course 0. So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency
matrices. Read more about how a graph is represented.
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
	visitedNodes.add(node.label);
	return true;
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
	for (int i = 0; i < numCourses; ++i)
	    nodes.add(new Node(i));
	for (int[] pair: prerequisites)
	    nodes.get(pair[0]).edges.add(pair[1]);

        visitedNodes = new ArrayList<>();
	for (int i = 0; i < numCourses; ++i)
	{
	    if (!dfs(i))
	        return new int[0];
	}

        int[] result = new int[numCourses];
	for (int index = 0; index < numCourses; ++index)
	    result[index] = visitedNodes.get(index);
        return result;
	
	// Stream in Java 8
	// return visitedNodes.stream().mapToInt(i->i).toArray();
    }

    List<Integer> visitedNodes;

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] prerequisites;
        int[] result;
        int numCourses;
    
        numCourses = 2;
        prerequisites = new int[][] {{1,0}};
        result = sol.findOrder(numCourses, prerequisites);
        for (int r: result)
            System.out.println(r);
    }
}


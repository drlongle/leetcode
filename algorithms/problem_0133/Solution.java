/*
133. Clone Graph
    Total Accepted: 80019
    Total Submissions: 321128
    Difficulty: Medium

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:
Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each
neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.
The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

import java.io.*;
import java.util.*;

public class Solution {
    Solution()
    {
	lookup = new HashMap<>();
    }
    Map<Node, Node> lookup;

    public Node cloneGraph(Node node) {
	if (node == null) return null;
	if (lookup.containsKey(node))
	    return lookup.get(node);
	Node newNode = new Node(node.val);
	lookup.put(node, newNode);
	for (Node neigh: node.neighbors)
	    newNode.neighbors.add(cloneGraph(neigh));

        return newNode;
    }
 
    public static void main(String[] args) {
        Solution sol = new Solution();
    }
}

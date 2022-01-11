/*
Use Floyd Warshall.

Convert given prerequisites into a DAG (Directed Acyclic Graph)
For every two vertices, check every intermediate vertex to see if a path is possible through it. Store this in a matrix. This takes O(n^3) time which is fine since n <= 100;
Queries can be done in O(1) time
 */

class Solution {
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& queries) {	           
		int i, j, k;
        vector<bool> ret(queries.size(), false);
		
        bool graph[n][n];
        memset(graph, false, sizeof(graph));

        for(i=0; i<p.size(); i++)
            graph[p[i][0]][p[i][1]] = true;
			
        for(k=0; k<n; k++)
            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);

		for(int i=0; i<queries.size(); i++)
            ret[i] = graph[queries[i][0]][queries[i][1]];

        return ret;
    }
};

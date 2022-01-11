class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Create a graph in the form of adjacency list from given vertices and edges.
        vector<vector<int>> graph(n);

        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Create an array for visited nodes
        vector<bool> visited(n, false);

        int numberOfConnectedComponents = 0;

        // For each of the unvisited nodes, do a BFS and mark all the nodes which are visited
        // during the BFS traversal
        for(int node = 0; node < n; node++){
            // If the node is visited previously, it is part of an already traversed connected component
            if(visited[node]) {
                continue;
            }

            // Otherwise, this is a new connected component
            numberOfConnectedComponents++;

            queue<int> q;
            q.push(node);

            while(!q.empty()){
                int currentNode = q.front();
                q.pop();
                visited[currentNode] = true;

                for(auto neighbor : graph[currentNode]) {
                    if(!visited[neighbor]) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return numberOfConnectedComponents;
    }
};

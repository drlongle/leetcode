
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<vector<int>> results;
	vector<int> wip;
	allPathsSourceTarget(graph, results, wip, 0, graph.size() - 1);

	return results;
    }

    void allPathsSourceTarget(
	vector<vector<int>> const& graph, 
	vector<vector<int>> & paths,
	vector<int> & wip,
	int const src, int const target) {

	wip.push_back(src);
	if (src == target) {
            paths.push_back(wip);
            wip.pop_back();
            return;
	}

	for (auto next : graph[src]) {
            allPathsSourceTarget(graph, paths, wip, next, target);
	}
	wip.pop_back();
    }

};

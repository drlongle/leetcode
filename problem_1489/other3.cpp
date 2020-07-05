class DisjointSet {
private:
    std::vector<int> _parent; // index
    std::vector<int> _rank;

    void link(int x, int y) {
        if (_rank[x] > _rank[y]) {
            _parent[y] = x;
        } else {
            _parent[x] = y;
            if (_rank[x] == _rank[y]) {
                ++_rank[y];
            }
        }
    }

public:
    explicit DisjointSet(int n): _parent(std::vector<int>(n, 0)), _rank(std::vector<int>(n, 1)) {
        for (int i = 0; i < n; ++i) {
            _parent[i] = i;
        }
    }

    int find_set(int i) {
        return _parent[i] == i ? _parent[i] : _parent[i] = find_set(_parent[i]);
    }

    void union_sets(int i, int j) {
        link(find_set(i), find_set(j));
    }
};

class Solution {
private:
    int mst(const int n, const std::vector<std::vector<int>>& edges, int forbiddenEdgeIdx = -1, int preEdgeIdx = -1) {
        DisjointSet disjointSet(n);
        int weight = 0;
        if (preEdgeIdx != -1) {
            disjointSet.union_sets(edges[preEdgeIdx][0], edges[preEdgeIdx][1]);
            weight += edges[preEdgeIdx][2];
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (forbiddenEdgeIdx == i) continue;
            if (disjointSet.find_set(edges[i][0]) != disjointSet.find_set(edges[i][1])) {
                disjointSet.union_sets(edges[i][0], edges[i][1]);
                weight += edges[i][2];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (disjointSet.find_set(i) != disjointSet.find_set(0)) {
                return 1e9;
            }
        }
        return weight;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].emplace_back(i);
        }
        std::sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[2] < rhs[2];
        });
        const auto minWeight = mst(n, edges);
        std::vector<int> criticalEdges;
        std::vector<int> pseudoCriticalEdges;
        for (int i = 0; i < edges.size(); ++i) {
            if (mst(n, edges, i) > minWeight) {
                criticalEdges.emplace_back(edges[i][3]);
            } else if (mst(n, edges, -1, i) == minWeight) {
                pseudoCriticalEdges.emplace_back(edges[i][3]);
            }
        }
        return {criticalEdges, pseudoCriticalEdges};
    }
};

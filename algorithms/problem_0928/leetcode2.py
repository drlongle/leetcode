class DSU:
    def __init__(self, N):
        self.p = range(N)
        self.sz = [1] * N

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[xr] = yr
        self.sz[yr] += self.sz[xr]

    def size(self, x):
        return self.sz[self.find(x)]


class Solution(object):
    def minMalwareSpread(self, graph, initial):
        N = len(graph)
        initial_set = set(initial)
        clean = [x for x in range(N) if x not in initial_set]

        # clean[u] == 1 if its a node in the graph not in initial.
        dsu = DSU(N)
        for u in clean:
            for v in clean:
                if graph[u][v]:
                    dsu.union(u, v)

        # dsu now represents the components of the graph without
        # any nodes from initial.  Let's call this graph G.
        count = collections.Counter()
        node_to_compo = {}
        for u in initial:
            components = set()
            for v in clean:
                if graph[u][v]:
                    components.add(dsu.find(v))
            node_to_compo[u] = components

            for c in components:
                count[c] += 1

        # For each node u in initial, nodeToCompo.get(u)
        # now has every component from G that u neighbors.

        best = (-1, None) # score, node
        for u, components in node_to_compo.iteritems():
            score = 0
            for c in components:
                if count[c] == 1: #uniquely infected
                    score += dsu.size(c)
            if score > best[0] or score == best[0] and u < best[1]:
                best = (score, u)

        return best[1]

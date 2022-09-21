class Solution {
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};

    public int cutOffTree(List<List<Integer>> forest) {
        List<int[]> trees = new ArrayList();
        for (int r = 0; r < forest.size(); ++r) {
            for (int c = 0; c < forest.get(0).size(); ++c) {
                int v = forest.get(r).get(c);
                if (v > 1) trees.add(new int[]{v, r, c});
            }
        }

        Collections.sort(trees, (a, b) -> Integer.compare(a[0], b[0]));

        int ans = 0, sr = 0, sc = 0;
        for (int[] tree: trees) {
            int d = cutOffTree(forest, sr, sc, tree[1], tree[2]);
            if (d < 0) return -1;
            ans += d;
            sr = tree[1]; sc = tree[2];
        }
        return ans;
    }

    // A* Search
    public int cutOffTree(List<List<Integer>> forest, int sr, int sc, int tr, int tc) {
        int R = forest.size(), C = forest.get(0).size();
        PriorityQueue<int[]> heap = new PriorityQueue<int[]>((a, b) -> Integer.compare(a[0], b[0]));
        heap.offer(new int[]{0, 0, sr, sc});

        HashMap<Integer, Integer> cost = new HashMap();
        cost.put(sr * C + sc, 0);

        while (!heap.isEmpty()) {
            int[] cur = heap.poll();
            int g = cur[1], r = cur[2], c = cur[3];
            if (r == tr && c == tc) return g;
            for (int di = 0; di < 4; ++di) {
                int nr = r + dr[di], nc = c + dc[di];
                if (0 <= nr && nr < R && 0 <= nc && nc < C && forest.get(nr).get(nc) > 0) {
                    int ncost = g + 1 + Math.abs(nr-tr) + Math.abs(nc-tr);
                    if (ncost < cost.getOrDefault(nr * C + nc, 9999)) {
                        cost.put(nr * C + nc, ncost);
                        heap.offer(new int[]{ncost, g+1, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
}

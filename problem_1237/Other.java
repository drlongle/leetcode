class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> sol = new ArrayList<>();
        for (int i = 1, j = z; i <= z && j >= 1;) {
            int val = customfunction.f(i, j);
            if (val > z) j--;
            else if (val == z) sol.add(Arrays.asList(i++,j--));
            else i++;
        }
        return sol;
    }
}

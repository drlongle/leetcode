/*
For each day, it could be covered by the tickets bought on today or before.
For each day, we check if it's in the days array. If not, then the cost should remain the same; otherwise, check today's cost could be coved by which day that will minimize total cost up to today.
*/

public int mincostTickets(int[] days, int[] costs) {
    int[] minCosts = new int[366];
    boolean[] isDays = new boolean[366];
    for(int day: days) isDays[day] = true;

    for(int i = 1; i <= 365; i++) {
        if(!isDays[i]) {
            minCosts[i] = minCosts[i - 1];
            continue;
        }
        int minCost;
        // case 1
        minCost = minCosts[i - 1] + costs[0];
        // case 2
        minCost = Math.min(minCost, minCosts[Math.max(0, i - 7)] + costs[1]);
        // case 3
        minCost = Math.min(minCost, minCosts[Math.max(0, i - 30)] + costs[2]);

        minCosts[i] = minCost;
    }

    return minCosts[365];
}


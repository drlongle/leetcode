/* Let minCost(i) denote the minimum cost that will be payed for all trips on days 1 to day 365.
The desired answer is then minCost(365).

Calculation minCost(i):

If no trip on day i, then minCost(i) = minCost(i-1).
minCost(i)=0 for all i ≤ 0.
Otherwise:
If a 1-day pass on day i. In this case, minCost(i) = minCost(i-1) + costs[0].
If a 7-day pass ending on day i. then : In this case, minCost(i) = min(minCost(i − 7), minCost(i − 6), …, minCost(i − 1)) + costs[1].
But since since minCost is increasing (adding a day never reduces the minCost) hence:
minCost(i) = minCost(i − 7) + costs[2]

Same case for 30-day pass also.
*/

public int mincostTickets(int[] days, int[] costs) {
    boolean[] dayIncluded = new boolean[366];
    for (int day : days) {
        dayIncluded[day] = true;
    }
    int[] minCost = new int[366];
    minCost[0] = 0;
    for (int day = 1; day <= 365; ++day) {
        if (!dayIncluded[day]) {
            minCost[day] = minCost[day-1];
            continue;
        }
        int min;
        min = minCost[day-1] + costs[0];
        min =Math.min(min, minCost[Math.max(0, day-7)] + costs[1]);
        min = Math.min(min, minCost[Math.max(0, day-30)] + costs[2]);
        minCost[day] = min;
    }

    return minCost[365];

}


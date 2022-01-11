/*
Model the problem using graph: each node/city can connect to itself and other nodes/cities if there is a flight.
each edge is weighted by the working days in the destination node/city (not vacation days)
Therefore the problem becomes a mininum weighted path with length k (weeks).
 */

struct CityNode{
public:
    int city;
    int week;
    int total_work_days;
    CityNode(int city_input, int week_input, int total_work_days_input) {
        city = city_input;
        week = week_input;
        total_work_days = total_work_days_input;
    }
};

class Solution {
public:
    int maxVacationDays(const vector<vector<int>>& flights, const vector<vector<int>>& days) {
        int num_cities = flights.size(), num_weeks = days[0].size();
        int num_days = num_weeks * 7;
        auto cmp = [](const CityNode& lhs, const CityNode& rhs) {
            return lhs.total_work_days > rhs.total_work_days;
        };
        std::priority_queue<CityNode, vector<CityNode>, decltype(cmp)> pq(cmp);
        pq.push(CityNode(0, -1, 0));
        vector<vector<int>> min_work_days_in_travel(num_cities, vector<int>(num_weeks, INT_MAX));
        while (pq.size()) {
            int city = pq.top().city, week = pq.top().week, total_work_days = pq.top().total_work_days;
            pq.pop();
            ++week;
            if (week == num_weeks) return num_days-total_work_days;
            // stay at city.

            CityNode node = CityNode(city, week, total_work_days+7-days[city][week]);
            if (node.total_work_days < min_work_days_in_travel[city][week]) {
                min_work_days_in_travel[city][week] = node.total_work_days;
                pq.push(node);
            }
            // travel from city
            for (int next = 0; next < num_cities; ++next) {
                if (flights[city][next] == 0) continue;
                CityNode next_node = CityNode(next, week, total_work_days+7-days[next][week]);
                if (next_node.total_work_days < min_work_days_in_travel[next][week]) {
                    min_work_days_in_travel[next][week] = next_node.total_work_days;
                    pq.push(next_node);
                }
            }
        }
        return -1;
    }
};

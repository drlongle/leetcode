struct Point
{
    Point(int po, int pa, int t): point(po), passengers(pa), type(t) {}
    int point, passengers, type;
    bool operator<(const Point& other) const
    {
        return point < other.point || (point == other.point && type < other.type);
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<Point> points;
        for(auto trip: trips)   {
            int c = trip[0], start = trip[1], end = trip[2];
            if (start != end) {
                points.emplace_back(start, c, 1);
                points.emplace_back(end, c, 0);
            } else
                points.emplace_back(end, c, 2);
        }
        sort(begin(points), end(points));
        int num = 0;
        for (auto& point: points)
        {
            if (point.type == 1 && point.passengers + num > capacity)
                return false;
            else if (point.type == 0)
                num -= point.passengers;
            else {
                num += point.passengers;
                if (num > capacity)
                    return false;
            }
        }

        return true;
    }
};

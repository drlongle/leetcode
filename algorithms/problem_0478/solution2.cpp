class Solution {
public:
    Solution(double radius, double x_center, double y_center):
            unif(-radius, radius), xc(x_center), yc(y_center), r(radius)
    {
    }

    vector<double> randPoint() {
        double x, y;
        while (true) {
            x = unif(re), y = unif(re);
            if (hypot(x, y) < r)
                break;
        }

        return vector<double> {xc + x, yc + y};
    }

    std::uniform_real_distribution<double> unif;
    std::default_random_engine re;
    double xc, yc, r;
};

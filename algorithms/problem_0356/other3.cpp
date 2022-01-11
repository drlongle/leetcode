class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {

        if (points.size()==1)
            return true;

        // sort vector by ascending x-value and if they matches then by ascending y-value
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) -> bool{
            if (a[0]==b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });

        // sort right half by descending y-value if x-value is same
        sort(points.begin()+points.size()/2, points.end(), [](const vector<int>& a, const vector<int>& b) -> bool{
            if (a[0]==b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        // if end points y-value are different then their x-value should be same i.e. they should fall on mirror
        if (points[0][1] != points.back()[1] && points[0][0] != points.back()[0])
            return false;

        // find the x-value of the mirror
        // mid of least and highest x-value (y-value should be same)
        float mirror_x = points[0][1] != points.back()[1] ? points[0][1] : (points[0][0] + points.back()[0])/2.0;

        // now using 2 pointers one from each of the end, compare the value of the pointer
        // their y-value should be same and their distance from mirror_x should be equal

        int i=1;
        int j = points.size()-2;
        while (i <= j) {
            if (points[i] == points[i-1] || points[i][0] == mirror_x){
                // same as prev point or point fall on mirror
                ++i; //cout << "skip" << points[i-1][0] << "," << points[i-1][1];
            }
            else if(points[j] == points[j+1] || points[j][0] == mirror_x){
                // same as prev point or point fall on mirror
                --j; //cout << "skip" << points[j+1][0] << "," << points[j+1][1];
            }
            else if (points[i][1] != points[j][1] || mirror_x-(float)points[i][0] != (float)points[j][0]-mirror_x)
                return false;   // distance from mirror not same
            else
            {++i;--j;}
        }

        return true;
    }
};

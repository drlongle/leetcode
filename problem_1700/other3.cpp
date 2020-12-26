class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c_pref = 0;
        int s_pref = 0;

        c_pref = count(students.begin(), students.end(), 0);
        s_pref = count(students.begin(), students.end(), 1);

        for (auto j : sandwiches) {
            if (j == 0) {
                c_pref --;
            }
            if (j == 1) {
                s_pref --;
            }
            if (c_pref < 0) {
                return s_pref;
            }
            if (s_pref < 0) {
                return c_pref;
            }
            if (c_pref == 0 && s_pref == 0) {
                return 0;
            }
        }

        return 0;
    }
};

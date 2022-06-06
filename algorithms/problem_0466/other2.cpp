class Solution {
  public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int s1size = s1.size();
        int s2size = s2.size();
        vector<int> dpm(s1size, INT_MAX / 2);

        // store in dpm[i] how many elements from s1 does it take starting from
        // ith element to make just one s2
        for (int i = 0; i < s1.size(); i++) {
            int p1 = i, p2{0};
            bool found = false;
            while (p1 < s1.size() * n1 && !found) {
                if (s2[p2] == s1[p1 % s1size]) {
                    p2++;
                    if (p2 == s2size)
                        found = true;
                }
                p1++;
            }
            if (found)
                dpm[i] = p1 - i;
        }

        // using dpm[i] calculate and store in number how many n2xs2 can be made
        // before a loop is made to go back to 0th element of s1 break when a
        // loop (back to 0th element is achieved)
        int p1{0}, s2count{0}, number{0};
        bool found = false;
        while (p1 <= s1size * n1) {
            if (s2count == n2) {
                s2count = 0;
                number++;
            }
            p1 = p1 + dpm[p1 % s1size];
            s2count++;

            if (p1 % s1size == 0) {
                found = true;
                break;
            }
        }

        // if no loop was found it is straightforward, just return the value of
        // number
        if (!found)
            return number;

        int remaining = n1 * s1size % p1;
        int rem{0}, pp{0}, s2countrem{0};

        // if there is loop it is straightforward to calculate the total number
        // occuring in the number of loops but we also need to find out how many
        // n2xs2 can be made outside of one incomplete loop
        while (pp <= remaining) {
            if (s2countrem == n2) {
                s2countrem = 0;
                rem++;
            }
            pp = pp + dpm[pp % s1size];
            s2countrem++;
        }

        long int temp = p1;
        temp = temp * n2 / s2count;

        int value = n1 * s1size / p1 * number + n1 * s1size / temp + rem;
        return value;
    }
};

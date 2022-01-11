class Solution {
    int count;
    /*
    1 2 3
    4 5 6
    7 8 9
    */
    // check if from i-->j,  it is a pass through if yes, return true and the id of the number in the middle
    bool passThrough(int i, int j, int& m)
    {
        if (i>j)  return passThrough (j,i, m); // swap i, j
        // now i<j; // enumerate all cases of pass through
        // horizontal
        if (i==1 && j==3) {m= 2 ; return true; }
        if (i==4 && j==6) {m= 5 ; return true; }
        if (i==7 && j==9) {m= 8 ; return true; }
        // vertical
        if (i==1 && j==7) {m= 4 ; return true; }
        if (i==2 && j==8) {m= 5 ; return true; }
        if (i==3 && j==9){m= 6 ; return true; }
        // diagonal
        if (i==1 && j==9) {m= 5 ; return true; }
        if (i==3 && j==7) {m= 5 ; return true; }
        return false;
    }
    void gen(vector<int>& path)
    {
        // stop condition
        if (path.size()>=_m && path.size()<=_n)  count++;
        if (path.size()==_n) return;

        // pick one of the remaining , valid number
        for (int i=1; i<=9; i++)
        {
            if (find(path.begin(), path.end(), i)== path.end()) // not used
            {
                int m;
                if (passThrough (path.back(), i, m))
                {
                    if (find(path.begin(), path.end(), m)!= path.end()) //  used
                    {
                        path.push_back(i);
                        gen (path);
                        path.pop_back();
                    }
                }
                else //next to each other or knight move
                {
                    path.push_back(i);
                    gen (path);
                    path.pop_back();
                }
            }

        }
    }
    int _m, _n;
public:
    int numberOfPatterns(int m, int n) {
        count =0;
        _m=m; _n=n;
        for (int i=1; i<=9; i++)
        {
            vector<int> path={i};
            gen(path);
        }
        return count;
    }
};

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto sqrdist = [](const vector<int>& p1, vector<int>& p2){
            return (p2[0]-p1[0]) * (p2[0]-p1[0]) + (p2[1]-p1[1]) * (p2[1]-p1[1]);};
        int a = sqrdist(p1, p2), b = sqrdist(p1, p3), c = sqrdist(p1, p4);
        return (a>0 && b >0 && c >0)
               && (   (a == b && sqrdist(p2, p4) == a && sqrdist(p3, p4) == a && c == sqrdist(p2, p3)) // diags : {p1, p4} and {p2, p3}
                      || (a == c && sqrdist(p2, p3) == a && sqrdist(p4, p3) == a && b == sqrdist(p2, p4)) // diags : {p1, p3} and {p2, p4}
                      || (sqrdist(p3, p2) == b && sqrdist(p4, p2) == b && a == sqrdist(p3, p4))); // diags : {p1, p2} and {p3, p4}
    }
};

string strWithout3a3b(int A, int B, const string& s="") {
    if (A == 0 || B == 0)
    {
        return s + string(A + B, A ? 'a' : 'b');
    }
    if (A > B)
    {
        if (s.size() < 2 || s.substr(s.size()-2) != "aa")
        {
            return strWithout3a3b(A - 1, B, s + "a");
        }
        return strWithout3a3b(A, B-1, s + "b");
    }
    else
    {
        if (s.size() < 2 || s.substr(s.size() - 2) != "bb")
        {
            return strWithout3a3b(A, B - 1, s + "b");
        }
        return strWithout3a3b(A - 1, B, s + "a");
    }
}

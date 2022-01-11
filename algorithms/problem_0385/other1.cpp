
NestedInteger deserialize(string& s, int from, int to) {        
    if (s[from] != '[') {
        return NestedInteger(stoi(s.substr(from, to - from)));
    }

    NestedInteger res;
    from++;
    to--;
    int prev = from, opened = 0;
    for (int i = from; i < to; ++i) {
        if (s[i] == '[') {
            opened++;
        } else if (s[i] == ']') {
            opened--;
        } else if (s[i] == ',' && opened == 0) {
            res.add(deserialize(s, prev, i));
            prev = i + 1;
        }
    }
    if (prev < to) {
        res.add(deserialize(s, prev, to));
    }
    return res;
}

NestedInteger deserialize(string s) {
    return deserialize(s, 0, s.size());
}


vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> map;
    vector<int> tmp, res;
    for(int i=0;i<arr2.size();i++) map[arr2[i]]=0;
    for(int i=0;i<arr1.size();i++) {
        if(map.find(arr1[i])!=map.end()) map[arr1[i]]++;
        else tmp.push_back(arr1[i]);
    }
    sort(tmp.begin(), tmp.end());
    for(int i=0;i<arr2.size();i++) {
        for(int j=0;j<map[arr2[i]];j++) res.push_back(arr2[i]);
    }
    for(int i=0;i<tmp.size();i++) res.push_back(tmp[i]);
    return res;
}


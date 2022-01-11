vector<vector> findSolution(CustomFunction& customfunction, int z) {
    vector<vector> ans;
    for(int x = 1; x <= 1000; x++)
    {
        for(int y = 1; y <= 1000; y++)
        {
            int k = customfunction.f(x,y);
            if(k == z)
            {
                vector tmp;
                tmp.push_back(x);
                tmp.push_back(y);
                ans.push_back(tmp);
            }
            else if(k > z)
            {
                break;
            }
        }
    }
    return ans;
}

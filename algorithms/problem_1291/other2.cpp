vector<int> sequentialDigits(int low, int high) {
	set <int> sequential;
    int i=1, j=1, seq=0;
    while(i<10) {
        seq = seq * 10 + j;
        sequential.insert(seq);
        if(j==9) {
            i++; seq=0; j=i;continue;
        }
        j++;
    }        
    auto firstIter = upper_bound(sequential.begin(), sequential.end(),low-1);
    auto lastIter = lower_bound(sequential.begin(), sequential.end(), high+1);
    return vector(firstIter, lastIter);
}

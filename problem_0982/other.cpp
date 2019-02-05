
/*
 First, we process all tuples A[i] and A[j], and store the result of A[i] & A[j] in the hash map tuples. We also count there how many times each result was produced.

Then, we go through the array again, and check each element against all tuples. If it produces zero, we add the tuple counter to the result.
*/

nt countTriplets(vector<int>& A, int cnt = 0) {
  unordered_map<int, int> tuples;
  for (auto a : A)
    for (auto b : A) ++tuples[a & b];
  for (auto a : A)
    for (auto t : tuples)
      if ((t.first & a) == 0) cnt += t.second;
  return cnt;
}

/*
If we know that the input is large, we could use an array instead of hash set. The size of this array will be 1 << 16. This will speed up things quite a bit.
*/

int countTriplets(vector<int>& A, int cnt = 0) {
  int tuples[1 << 16] = {};
  for (auto a : A)
    for (auto b : A) ++tuples[a & b];
  for (auto a : A)
    for (auto i = 0; i < (1 << 16); ++i)
      if ((i & a) == 0) cnt += tuples[i];
  return cnt;
}


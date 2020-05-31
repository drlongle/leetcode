class Solution {
public:
    bool hasAllCodes(string s, int k) 
	{
		long long x=pow((long long)2,(long long)k); //calculating no. of possible binary strings of size k
		if(s.size()<x)return false;
		unordered_set<long long> ss;
		for(int i=0;i+k-1<s.size();i++)
            ss.insert(stol(s.substr(i,k))); //generating all possible substrings of size k using given string
		return (ss.size()==x); //checking the final condition
	}
};

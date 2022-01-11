class RLEIterator {
public:
    RLEIterator(vector<int> A) {// O(n) time 
		loc=0;
        sum=0;
		cnt.push_back(0);
		num.push_back(-1); 
		for( int i=0; i<A.size(); i+=2){
			cnt.push_back(cnt.back()+A[i]); 
			num.push_back(A[i+1]); 
		}
    }
    
    int next(int n) {// O(log(n)) time
		sum+=n;
		if(cnt.back()<sum)	return -1;
		int b=loc, e=cnt.size()-1, mid;// (b,e]
		while(b+1<e){
			mid=b+(e-b)/2;
			if(cnt[mid]<sum)	b=mid;
			else	e=mid;
		}
		loc=b;// update begining point to speed up binary search 
		return num[e];
    }
	
protected:
	int loc;// current location 
	long sum;// total count 
	vector<long> cnt;// count 
	vector<int> num;// number value 
};

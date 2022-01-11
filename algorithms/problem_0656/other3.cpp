class Solution {

    static const int MAXN = 1010;

public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int next_stop[MAXN];
        int payment[MAXN];
        int i = A.size() - 1;
        deque <int> dq;
        next_stop[i] = 0;
        payment[i] = A[i];

        vector <int > ret;
        if (A[i] == -1){return ret;}
        dq.push_back(i);
        while(i >= 0){

            if( A[i] != -1 ){
                while (!dq.empty() && dq.back() > i + B ){
                    dq.pop_back();
                }

                if (!dq.empty()){
                    next_stop[i] = dq.back();
                    payment[i] = payment[next_stop[i]] + A[i];

                    if (A[i] == 0 ){
                        dq.clear(); // dump all
                    }

                    while (!dq.empty() &&
                           payment[i] <= payment[dq.front()]
                            ){
                        dq.pop_front();
                    }
                    dq.push_front(i);

                }else{
                    return ret;
                }
            }
            i--;
        }

        i = 0;
        while(i != A.size() - 1){
            ret.push_back(i + 1);
            i = next_stop[i];
        }
        ret.push_back(A.size() );
        return ret;
    }
};

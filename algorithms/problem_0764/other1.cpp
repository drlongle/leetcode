
class Solution {
    typedef std::vector<std::vector<int16_t>> mp_v_t;  
    int N;
    inline int16_t gmd(const std::vector<int16_t> &v, int k) const {
        if( v.empty() )
            return min(k + 1, N - k);
        if( v.size() < 2 )
            return min({k + 1, N - k, std::abs(k - v.front())});  
        auto it = std::upper_bound(v.cbegin(), v.cend(), k);
        if( it == v.cend() )
            return min(k - v.back(), N - k);
        if( it == v.cbegin() )
            return min(k + 1, v.front() - k);

        auto itn = it--;
        return min(k - *it, *itn - k); 
    }
    
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if( N == 0 || N * N == mines.size() )
            return 0;
        if( N * N - mines.size() < 5)
            return 1;
        if( mines.size() == 0) {
            return (N + 1) / 2;  
        }
        this->N = N;
        mp_v_t a_i(N);
        mp_v_t a_j(N);  
        for(const auto &x : mines) {
            a_i[x[0]].emplace_back(x[1]);
            a_j[x[1]].emplace_back(x[0]); 
        }
        for(int k = 0; k < N; k++) {
            if( a_i[k].size() > 1 )  
                std::sort(a_i[k].begin(), a_i[k].end());
            if( a_j[k].size() > 1 )  
                std::sort(a_j[k].begin(), a_j[k].end());  
        }
        int16_t result = 0;  
        for(int l = N / 2; l >= 0; l--) {
            if( result >= l + 1 )
                break;
            int dl = N - l - 1;
            for(int k = l; k < N - l; k++) {
                result = max({result, min(gmd(a_i[l], k), gmd(a_j[k], l)), 
                              min(gmd(a_i[dl], k), gmd(a_j[k], dl)),
                              min(gmd(a_i[k], l), gmd(a_j[l], k)),
                              min(gmd(a_i[k], dl), gmd(a_j[dl], k))});  
                if( result >= l + 1 )
                    break;
            }
        }
        return result;  
    }
};

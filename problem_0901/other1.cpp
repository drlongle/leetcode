class StockSpanner {
    int day;
    stack< array<int, 2> > s;
public:
    StockSpanner() { this->day = 0; }
    
    int next( int price ) {
        ++day;
        int count;
        if( s.empty() ) {
            s.push( { price, day } );
            count = 1;
        } else if( s.top()[0] > price ) {
            count = day - s.top()[1];
            s.push( { price, day } );
        } else {
            while( !s.empty() && price >= s.top()[0] ) 
                s.pop();
            if( s.empty() ) count = day;
            else count = day - s.top()[1];
            
            s.push( {price, day } );
        }
        return count;
    }
};


public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        
        // we begin with any station and the
        // current station we're trying to complete is end
        int begin = 0, end = begin;        
        int stationsVisited = 0;
        int fuel = 0;
        
        // we continue checking until we've tried covering all
        // stations / tried beginning from each station to compensate
        // for fuel deficiency in subsequent stations
        while(stationsVisited < n) {
            
            // when we're at station end, we check if fuel_cost combination
            // at end allows us to go further (with >= 0 residual fuel afterwards)
            int residual = fuel + (gas[end] - cost[end]);
            
            if(residual >= 0) {
                fuel += gas[end] - cost[end];
                end = (end + 1) % n;                
            } else {
                // if the residual fuel is negative, it means we might
                // have better success, if we began from one station earlier instead
                begin = (begin-1+n) % n;
                fuel += gas[begin] - cost[begin];
            }
            
            // at every iteration, we're either visiting the current (i.e. end) station
            // or we're considering starting journey from the station prior to begin 
            stationsVisited++;
        }
        
        // eventually in adverse scenario, we'd have
        // tried starting from every station
        // if overall fuel is still non-negative, it means entire journey was feasible
        return (fuel >= 0) ? begin: -1;
    }


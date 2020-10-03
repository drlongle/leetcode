class ParkingSystem {
public:
    vector<int> p;
    ParkingSystem(int big, int medium, int small) {
        p = {0, big, medium, small};
    }
    bool addCar(int carType) {
        return --p[carType] >= 0;
    }
};
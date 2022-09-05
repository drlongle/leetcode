class Solution {
  public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int size = cars.size();

        vector<double> result(size, -1);

        vector<int> dpTimeNum(
            size,
            -1); // save numerator of time taken by ith car to make a collision
        vector<int> dpTimeDen(
            size,
            1); // save denominator of time taken by ith car to make a collision
        vector<int> dpCollision(
            size, -1); // save index of the car the i'th car collides with in
                       // future and becomes the same speed

        auto timeToCollide = [&](int idx1, int idx2) {
            int pos1 = cars[idx1][0], speed1 = cars[idx1][1];
            int pos2 = cars[idx2][0], speed2 = cars[idx2][1];

            if (speed1 <= speed2) {
                return make_pair(INT_MAX, 1);
            }

            return make_pair(pos2 - pos1, speed1 - speed2);
        };

        for (int idx = size - 2; idx >= 0; idx--) {

            // We start off with next index as collisionIndex and test whether
            // we will actually collide with it or we need to go to the index
            // collisionIndex collides with.
            int collisionIdx = idx + 1;
            while (collisionIdx != -1) {

                auto currCollitionTime = timeToCollide(idx, collisionIdx);

                // If my currSpeed is less than collisionIdx car speed
                // Then i will probably collide with the car collisionIdxCar
                // collides with in future
                if (currCollitionTime.first == INT_MAX) {
                    collisionIdx = dpCollision[collisionIdx];
                }
                // If my currSpeed is greater than collisionIdx car speed
                // But before i collide with collisionIdx car it collides with
                // some other car
                else if (dpCollision[collisionIdx] != -1 &&
                         currCollitionTime.first * 1LL *
                                 dpTimeDen[collisionIdx] >=
                             dpTimeNum[collisionIdx] * 1LL *
                                 currCollitionTime.second) {
                    collisionIdx = dpCollision[collisionIdx];
                }
                // Found a car to collide with
                else {
                    dpCollision[idx] = collisionIdx;
                    dpTimeNum[idx] = currCollitionTime.first;
                    dpTimeDen[idx] = currCollitionTime.second;
                    break;
                }
            }

            result[idx] = dpTimeNum[idx];
            result[idx] /= dpTimeDen[idx];
        }

        return result;
    }
};

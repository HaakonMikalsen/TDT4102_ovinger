#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"

int main() {
    for (int i = 0; i < 10; i++) {
        int numbers = randomWithLimits(5, 10);
        cout << numbers << endl;
    }

    double maxError = 0.005;
    testDeviation(posX(0.0, 50.0, 5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");
    testDeviation(posX(0.0, 50.0, 2.5), 125, maxError, "posX(0.0,50.0,2.5)");

    testDeviation(posY(0.0, 25.0, 5.0), 2.375, maxError, "posY(0.0,25.0,5.0)");
    testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0,25.0,2.5)");

    playTargetPractice();

    // testDeviation(velY(25, 2.5), 0.475, maxError, "velY(25,2.5)");
    // testDeviation(velY(25, 5), -24.05, maxError, "velY(25,5)");
    // vector<double> vec = getVelocityVector(getUserInputTheta(), getUserInputInitVelocity());
    // cout << vec.at(0) << " , " << vec.at(1) << endl;
    // cout << getDistanceTraveled(vec.at(0), vec.at(1)) << endl;
    // cout << targetPractice(23, vec.at(0), vec.at(1)) << endl;
    return 0;
}
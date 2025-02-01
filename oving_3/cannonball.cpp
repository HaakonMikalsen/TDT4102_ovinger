#include "cannonball.h"
#include "cannonball_viz.h"
#include "utilities.h"

// BEGIN: 2a
// Implementer funksjonen acclY
double acclY()
{
    return -9.81;
}
// END: 2a

// BEGIN: 2b
// Implementer funksjonen velY
double velY(double initVelocityY, double time)
{
    return initVelocityY + (acclY() * time);
}
// END: 2b

// BEGIN: 2c
// Implementer funksjonene posX og posY
double posX(double initPositionX, double initVelocityX, double time)
{
    return initPositionX + (initVelocityX * time);
}
double posY(double initPositionY, double initVelocityY, double time)
{
    return initPositionY + (initVelocityY * time) + ((acclY() * pow(time, 2)) / 2);
}
// END: 2c

// BEGIN: 2d
// Implementer funksjonen printTime
void printTime(double time)
{
    double remainder = time;
    int hours = remainder / 3600;
    remainder -= hours * 3600;
    int minutes = remainder / 60;
    remainder -= minutes * 3600;
    cout << hours << "h " << minutes << "m " << remainder << "s " << endl;
}
// END: 2d

// BEGIN: 2e
// Implementer funksjonen flightTime
double flightTime(double initVelocityY)
{
    return (((-2) * initVelocityY) / acclY());
}
// END: 2e

// BEGIN: 3b
// Implementer funksjonen testDeviation

bool testDeviation(double compareOperand, double toOperand, double maxError, string name)
{
    if (abs(compareOperand - toOperand) <= maxError)
    {
        cout << "Test: " << name << " passed" << endl;
        return true;
    }
    cout << "Test: " << name << " failed." << "Expected " << toOperand << " got " << compareOperand << endl;
    return false;
}
// END: 3b

// BEGIN: 4a
// Her skal du implementere ALLE funksjonene i oppgave 4a
// Ber brukeren om en vinkel i grader
double getUserInputTheta()
{
    cout << "Input angle" << endl;
    double theta = 0;
    cin >> theta;
    return theta;
}
// Ber brukeren om en startfart
double getUserInputInitVelocity()
{
    cout << "Input startVelocity" << endl;
    double startVel = 0;
    cin >> startVel;
    return startVel;
}
// Konverterer fra grader til radianer
double degToRad(double deg)
{
    constexpr double convRate = (pi / 180);
    return deg * convRate;
}
// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity)
{
    return initVelocity * cos(degToRad(theta));
}
double getVelocityY(double theta, double initVelocity)
{
    return initVelocity * sin(degToRad(theta));
}
// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
// x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double initVelocity)
{
    vector<double> vel = {getVelocityX(theta, initVelocity), getVelocityY(theta, initVelocity)};
    return vel;
}

// END: 4a

// BEGIN: 4b
double getDistanceTraveled(double velocityX, double velocityY)
{
    return posX(0, velocityX, flightTime(velocityY));
}
// END: 4b

// BEGIN: 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

// END: 4c

// BEGIN: 5b
void playTargetPractice()
{
    const int targetPoint = randomWithLimits(100, 1000);
    string message = "You lost:(";
    for (int i = 0; i < 10; i++)
    {
        double theta = getUserInputTheta();
        theta = degToRad(theta);
        double startV = getUserInputInitVelocity();
        vector<double> velocity = getVelocityVector(theta, startV);
        double dist = targetPractice(targetPoint, velocity.at(0), velocity.at(1));
        cout << "your shot was in the air for: ";
        printTime(flightTime(velocity.at(1)));
        cout << "You shot " << abs(dist) << " too" << ((dist < 0) ? "long" : "short") << endl;
        if (abs(dist) < 5)
        {
            message = "You won! :) ";
        }
    }
    cout << message << endl;
}
// END: 5b

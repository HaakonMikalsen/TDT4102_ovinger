// handout oving 2

#include "std_lib_facilities.h"
#include "AnimationWindow.h"

void inputAndPrintInteger()
{
    // BEGIN: 1b
    int tall = 0;
    cout << "Skriv inn et heltall: ";
    cin >> tall;
    cout << "Du skrev inn: " << tall << endl;

    // END: 1b
}

int inputInteger()
{
    // BEGIN: 1c
    int tall = 0;
    cout << "Skriv inn et heltall: ";
    cin >> tall;

    return tall;
    // END: 1c
}

void printSumOfInputIntegers()
{
    // BEGIN: 1d
    int number1 = 0;
    int number2 = 0;
    number1 = inputInteger();
    number2 = inputInteger();
    cout << "Summen av tallene: " << number1 + number2 << endl;
    // END: 1d
}

bool isOdd(int n)
{
    // BEGIN: 1f
    if (n % 2 == 0)
    {
        return false;
    }
    return true;
    // END: 1f
}

void inputIntegersAndPrintSum()
{
    // BEGIN: 2a
    int summMegnde = 0;
    int sum = 0;
    cout << "Skriv inn hvor mange tall du vil summere: ";
    cin >> summMegnde;
    cout << endl;
    for (int i = 1; i <= summMegnde; i++)
    {
        sum += inputInteger();
    }
    cout << "Summen av tallene er: " << sum << endl;

    // END: 2a
}

void inputIntegersAndPrintSumUntilStopped()
{
    // BEGIN: 2b
    int sum = 0;
    int input = -1;
    cout << endl;
    while (input != 0)
    {
        input = inputInteger();
        sum += input;
    }
    cout << "Summen av tallene er: " << sum << endl;

    // END: 2b
}

double inputDouble()
{
    // BEGIN: 2d
    double tall = 0;
    cout << "Skriv inn et tall: ";
    cin >> tall;

    return tall;
    // END: 2d
}

void convertNOKtoEUR()
{
    // BEGIN: 2e
    double tall = -1;
    double convRate = 1 / 10.5;
    while (tall < 0)
    {
        tall = inputDouble() * convRate;
    }
    cout << "Det er ";
    cout << fixed << setprecision(2) << tall;
    cout << "euro" << endl;
    // END: 2e
}

void printMultiplicationTable()
{
    // BEGIN: 2g
    int width = 0;
    int height = 0;
    cout << "Enter height: ";
    cin >> height;
    cout << endl
         << "Enter width: ";
    cin >> width;
    cout << endl
         << setw(5);
    for (int y = 1; y <= height; y++)
    {
        for (int x = 1; x <= width; x++)
        {
            cout << x * y
                 << setw(5);
        }
        cout << endl;
    }
    // END: 2g
}

double discriminant(double a, double b, double c)
{
    // BEGIN: 3a
    return pow(b, 2) + (4 * a * c);
    // END: 3a
}

void printRealRoots(double a, double b, double c)
{
    // BEGIN: 3b
    double presiconZero = 0.001;
    double dis = discriminant(a, b, c);
    if (dis < 0)
    {
        cout << "Has no roots" << endl;
        return;
    }
    if (abs(dis) < presiconZero)
    {
        dis = sqrt(dis);
        double x1 = ((-b) + dis) / (2 * a);
        cout << "It has the root: " << x1 << endl;
        return;
    }
    dis = sqrt(dis);
    double x1 = ((-b) + dis) / (2 * a);
    double x2 = ((-b) - dis) / (2 * a);
    cout << "It has the roots: " << x1 << " og " << x2 << endl;
    // END: 3b
}

void solveQuadraticEquations()
{
    // BEGIN: 3c
    cout << "Skriv inn henholdsvis a,b og c" << endl;
    double a = inputDouble();
    double b = inputDouble();
    double c = inputDouble();
    printRealRoots(a, b, c);
    // END: 3c
}

void pythagoras()
{
    // BEGIN: 4a
    // Alle deloppgaver i 4 skal løses her
    const int w = 400;
    const int h = 400;
    AnimationWindow win{100, 100, w, h, "Pythagoras"};

    const int scale = 3;
    const int A = 30 * scale;
    const int B = 40 * scale;
    const int C = 50 * scale;

    const Point point1{150, 100};
    const Point point2{point1.x, point1.y + B};
    const Point point3{point1.x + A, point1.y + B};

    win.draw_triangle(point1, point1, point3, Color::red);
    win.draw_quad(Point{point1.x, point1.y}, Point{point1.x - B, point1.y}, Point{point1.x - B, point1.y + B}, Point{point1.x, point1.y + B}, Color::green);
    win.draw_quad(Point{point2.x, point2.y}, Point{point2.x + A, point2.y}, Point{point2.x + A, point2.y + A}, Point{point2.x, point2.y + A}, Color::green);
    win.draw_quad(Point{point1.x, point1.y}, Point{point1.x + B, point1.y - A}, Point{point3.x + B, point3.y - A}, Point{point3.x, point3.y}, Color::green);

    win.wait_for_close();
    // END: 4a
}

vector<int> calculateBalance(int amount, int rate, int years)
{
    // BEGIN: 5a
    vector<int> saldo(years);
    saldo.at(0) = amount;
    for (int i = 1; i < years; i++)
    {
        cout << i << " " << saldo.at(i) << endl;
        saldo.at(i) = saldo.at(i - 1) + saldo.at(i - 1) * (static_cast<double>(rate) / 100);
    }
    return saldo;
    // END: 5a
}

void printBalance(vector<int> balanceVec)
{
    // BEGIN: 5b
    const int printWidth = 10;

    cout << "År"
         << setw(printWidth);

    cout << "Salod"
         << setw(printWidth)
         << endl;

    for (int i = 0; i < balanceVec.size(); i++)
    {
        cout << i
             << setw(printWidth);
        cout << balanceVec.at(i)
             << setw(printWidth)
             << endl;
    }

    // END: 5b
}

int main()
{
    // Oppgave 1a
    // Her kan du teste funksjonene dine ved hjelp av menysystem som beskrevet.
    // NB: Denne delen av  koden blir IKKE automatisk rettet.

    // vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // for (int i = 0; i <= v.size(); i++)
    // {
    //     cout << v.at(i) << endl;
    // }
    int valg = -1;
    int number = 0;
    double numberD = 0;
    while (valg != 0)
    {
        cout << "velg funksjon" << endl;
        // cout << "0) Avslutte" << endl;
        // cout << "1) Skrive inn tall og ut tall" << endl;
        // cout << "2) Skrive inn tall" << endl;
        // cout << "3) Skrive og summere tall" << endl;
        // cout << "4) Test funk odd" << endl;
        // cout << "5) Summere tall" << endl;
        // cout << "6) Summere tall helt til du skriver 0" << endl;
        // cout << "7) Skrive inn double" << endl;
        // cout << "8) NOK TIL EURO" << endl;
        // cout << "9) Gange tabell" << endl;
        // cout << "Angi valg fra 0-4" << endl;

        cin >> valg;
        switch (valg)
        {
        case 1:
            inputAndPrintInteger();
            break;
        case 2:
            number = inputInteger();
            cout << "Du skrev inn: " << number << endl;
            break;
        case 3:
            printSumOfInputIntegers();
            break;
        case 4:
            for (int i = 0; i <= 15; i++)
            {
                cout << isOdd(i) << endl;
            }
            break;
        case 5:
            inputIntegersAndPrintSum();
            break;
        case 6:
            inputIntegersAndPrintSumUntilStopped();
            break;
        case 7:
            numberD = inputDouble();
            cout << "Du skrev inn: " << numberD << endl;
            break;

        case 8:
            convertNOKtoEUR();
            break;
        case 9:
            printMultiplicationTable();
            break;

        case 10:
            cout << discriminant(3, 2, 5);
            break;

        case 11:
            printRealRoots(3, 2, 5);
            break;

        case 12:
            solveQuadraticEquations();
            break;
        case 13:
            pythagoras();
            break;

        case 14:
            printBalance(calculateBalance(5000, 3, 10));
            break;
        }
    }

    return 0;
}

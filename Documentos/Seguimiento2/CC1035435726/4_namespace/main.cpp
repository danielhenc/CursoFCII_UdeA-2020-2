#include "numOp.cpp"

using namespace numOp;

int main()
{
    double testNums[10] = { 1.3, 3.5, 4.6, 500.40, 38.983, 21.398, 2.1, -1.3, 33.11, 1000.5 };
    //punto 5b
    cout << "Test funcion entero()" << endl;
    cout << setw(7) << "double" << setw(7) << "entero" << endl;
    for (int i = 0; i < 10; i++) {
        cout << setw(7) << testNums[i] << setw(7) << entero(testNums[i]) << endl;
    }
    
    //punto 6b
    cout << "Test funcion partefracc()" << endl;
    cout << setw(7) << "double" << setw(7) << "fracc" << endl;
    for (int i = 0; i < 10; i++) {
        cout << setw(7) << testNums[i] << setw(7) << partefracc(testNums[i]) << endl;
    }
}

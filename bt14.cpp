#include <iostream>
#include <cmath>
using namespace std;

double tinhSin(double x) {
    double result = 0;
    double term = x; // term is the first term x^1 / 1!
    int n = 1;
    
    while (abs(term) >= 0.00001) {
        result += term;
        term *= -x * x / ((2 * n) * (2 * n + 1));  // next term in the series
        n++;
    }

    return result;
}

int main() {
    double x;
    cout << "Nhap x (rad): ";
    cin >> x;

    cout << "Sin(x) = " << tinhSin(x) << endl;
    return 0;
}

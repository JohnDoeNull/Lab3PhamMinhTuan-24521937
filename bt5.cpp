#include <iostream>
#include <vector>
using namespace std;

class cDaThuc {
private:
    vector<int> coeffs;

public:
    cDaThuc(initializer_list<int> coefs) : coeffs(coefs) {}

    double giaTri(double x) {
        double result = 0;
        for (int i = 0; i < coeffs.size(); i++) {
            result += coeffs[i] * pow(x, coeffs.size() - 1 - i);
        }
        return result;
    }

    void xuat() {
        for (int i = 0; i < coeffs.size(); i++) {
            cout << coeffs[i] << "x^" << coeffs.size() - 1 - i;
            if (i != coeffs.size() - 1) cout << " + ";
        }
        cout << endl;
    }

    cDaThuc operator+(const cDaThuc& other) {
        int n = max(coeffs.size(), other.coeffs.size());
        vector<int> newCoeffs(n, 0);
        for (int i = 0; i < coeffs.size(); i++) newCoeffs[i] += coeffs[i];
        for (int i = 0; i < other.coeffs.size(); i++) newCoeffs[i] += other.coeffs[i];
        return cDaThuc(newCoeffs);
    }
};

int main() {
    cDaThuc d1 = {1, -2, 3};
    cDaThuc d2 = {2, 3};
    cout << "Đa thức 1: ";
    d1.xuat();
    cout << "Đa thức 2: ";
    d2.xuat();
    cDaThuc d3 = d1 + d2;
    cout << "Tổng của 2 đa thức: ";
    d3.xuat();
    return 0;
}

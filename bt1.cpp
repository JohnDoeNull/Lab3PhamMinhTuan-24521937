#include <iostream>
#include <cmath>
using namespace std;

class cTamGiac {
private:
    float A, B, C;

public:
    cTamGiac(float A, float B, float C) : A(A), B(B), C(C) {}

    float tinhChuVi() {
        return A + B + C;
    }

    float tinhDienTich() {
        float p = tinhChuVi() / 2;
        return sqrt(p * (p - A) * (p - B) * (p - C));
    }

    string kiemTraLoaiTamGiac() {
        if (A == B && B == C) return "Đều";
        if (A == B || B == C || A == C) return "Cân";
        if (pow(A, 2) + pow(B, 2) == pow(C, 2) || pow(A, 2) + pow(C, 2) == pow(B, 2) || pow(B, 2) + pow(C, 2) == pow(A, 2))
            return "Vuông";
        return "Thường";
    }
};

int main() {
    cTamGiac tg(3, 4, 5);
    cout << "Chu vi: " << tg.tinhChuVi() << endl;
    cout << "Diện tích: " << tg.tinhDienTich() << endl;
    cout << "Loại tam giác: " << tg.kiemTraLoaiTamGiac() << endl;
    return 0;
}

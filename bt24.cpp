#include <iostream>
using namespace std;

class GioPhutGiay {
private:
    int iGio, iPhut, iGiay;

public:
    void Nhap() {
        cout << "Nhap gio: ";
        cin >> iGio;
        cout << "Nhap phut: ";
        cin >> iPhut;
        cout << "Nhap giay: ";
        cin >> iGiay;
    }

    void Xuat() {
        cout << iGio << ":" << iPhut << ":" << iGiay << endl;
    }

    void TinhCongThemMotGiay() {
        iGiay++;
        if (iGiay == 60) {
            iGiay = 0;
            iPhut++;
        }
        if (iPhut == 60) {
            iPhut = 0;
            iGio++;
        }
        if (iGio == 24) {
            iGio = 0;
        }
    }
};

int main() {
    GioPhutGiay gio;
    gio.Nhap();
    gio.Xuat();
    gio.TinhCongThemMotGiay();
    cout << "Gio sau khi cong them 1 giay: ";
    gio.Xuat();
    return 0;
}

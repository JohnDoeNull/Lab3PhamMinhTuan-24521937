#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int ngay, thang, nam;

    bool laNamNhuan(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool kiemTraNgayHopLe() {
        if (thang < 1 || thang > 12) return false;
        int daysInMonth[] = {31, (laNamNhuan(nam) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return ngay >= 1 && ngay <= daysInMonth[thang - 1];
    }

public:
    void Nhap() {
        do {
            cout << "Nhap ngay (1-31): ";
            cin >> ngay;
            cout << "Nhap thang (1-12): ";
            cin >> thang;
            cout << "Nhap nam: ";
            cin >> nam;
        } while (!kiemTraNgayHopLe());
    }

    void Xuat() {
        cout << "Ngay " << ngay << "/" << thang << "/" << nam << endl;
    }

    void NgayTiepTheo() {
        int daysInMonth[] = {31, (laNamNhuan(nam) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (ngay == daysInMonth[thang - 1]) {
            ngay = 1;
            thang++;
            if (thang == 13) {
                thang = 1;
                nam++;
            }
        } else {
            ngay++;
        }
    }
};

int main() {
    NgayThangNam nt;
    nt.Nhap();
    nt.Xuat();
    nt.NgayTiepTheo();
    cout << "Ngay tiep theo: ";
    nt.Xuat();
    return 0;
}

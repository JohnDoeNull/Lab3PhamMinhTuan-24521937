#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

public:
    void Nhap() {
        cout << "Nhap ngay: ";
        cin >> iNgay;
        cout << "Nhap thang: ";
        cin >> iThang;
        cout << "Nhap nam: ";
        cin >> iNam;
    }

    void Xuat() {
        cout << "Ngay " << iNgay << " Thang " << iThang << " Nam " << iNam << endl;
    }

    void NgayThangNamTiepTheo() {
        if (iNgay == 31) {
            iNgay = 1;
            iThang++;
            if (iThang > 12) {
                iThang = 1;
                iNam++;
            }
        } else {
            iNgay++;
        }
    }
};

int main() {
    NgayThangNam ngay;
    ngay.Nhap();
    ngay.Xuat();
    ngay.NgayThangNamTiepTheo();
    cout << "Ngay thang nam tiep theo: ";
    ngay.Xuat();
    return 0;
}

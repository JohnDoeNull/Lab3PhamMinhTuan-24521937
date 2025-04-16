#include <iostream>
#include <vector>
using namespace std;

class cDaGiac {
private:
    vector<float> canh;

public:
    void themCanh(float c) {
        canh.push_back(c);
    }

    float tinhChuVi() {
        float chuVi = 0;
        for (float c : canh) chuVi += c;
        return chuVi;
    }

    void xuatCanh() {
        for (float c : canh) cout << c << " ";
        cout << endl;
    }
};

int main() {
    cDaGiac daGiac;
    daGiac.themCanh(3);
    daGiac.themCanh(4);
    daGiac.themCanh(5);
    cout << "Chu vi đa giác: " << daGiac.tinhChuVi() << endl;
    cout << "Các cạnh đa giác: ";
    daGiac.xuatCanh();
    return 0;
}

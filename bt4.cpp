#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class cArray {
private:
    vector<int> arr;

public:
    cArray(int n) {
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr.push_back(rand() % 100 + 1);  // Tạo số ngẫu nhiên từ 1 đến 100
        }
    }

    void xuat() {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    int demXuatHien(int x) {
        return count(arr.begin(), arr.end(), x);
    }

    bool kiemTraTangDan() {
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) return false;
        }
        return true;
    }

    int timSoLeNhoNhat() {
        int minOdd = 101; // Chỉ có thể là số > 100
        for (int num : arr) {
            if (num % 2 != 0 && num < minOdd) {
                minOdd = num;
            }
        }
        return minOdd;
    }
};

int main() {
    cArray array(10);
    cout << "Mảng: ";
    array.xuat();
    cout << "Số lần xuất hiện của 5: " << array.demXuatHien(5) << endl;
    cout << "Mảng có tăng dần không? " << (array.kiemTraTangDan() ? "Có" : "Không") << endl;
    cout << "Số lẻ nhỏ nhất trong mảng: " << array.timSoLeNhoNhat() << endl;
    return 0;
}

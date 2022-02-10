#include <bits/stdc++.h>

using namespace std;

void generate_barcode(int &a, int &b, int count, int len, vector<bool> &barcode) {
    if (len < b) {
        if (b - len + count > a) {
            barcode[len] = false;
            generate_barcode(a, b, count, len + 1, barcode);
        }
        if (count < a) {
            barcode[len] = true;
            generate_barcode(a, b, count + 1, len + 1, barcode);
        }
    } else {
        for (int i = 0; i < b; ++i)
            cout << barcode[i];
        cout << "\n";
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<bool> barcode(b);
    generate_barcode(a, b, 0, 0, barcode);
}
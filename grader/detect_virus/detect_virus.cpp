#include <bits/stdc++.h>

using namespace std;

bool isVirus(vector<int> &dna, int s, int e) {
    if (e - s == 2)
        return !dna[s] & dna[s + 1];
    int m = (s + e) >> 1;
    bool a = isVirus(dna, s, m);
    vector<int> tmp(m - s);
    for (int i = 0; i < m - s; ++i)
        tmp[i] = dna[m - i - 1];
    bool b = isVirus(tmp, 0, m - s);
    bool c = isVirus(dna, m, e);
    return (a || b) && c;
}

int main() {
    int n, k;
    cin >> n >> k;
    int size = 1 << k;
    vector<int> dna(size);
    while (n--) {
        for (int i = 0; i < size; ++i) {
            cin >> dna[i];
        }
        cout << (isVirus(dna, 0, size) ? "yes\n" : "no\n");
    }
}

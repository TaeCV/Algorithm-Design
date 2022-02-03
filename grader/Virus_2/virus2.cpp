#include <bits/stdc++.h>

using namespace std;

pair<bool, int> isVirus(vector<int> &dna, int s, int e) {
    if (e - s == 2) {
        int cnt = 0;
        for (int i = s; i < e; ++i) {
            cnt += dna[i];
        }
        return {true, cnt};
    }
    int m = (s + e) >> 1;
    pair<bool, int> v1 = isVirus(dna, s, m);
    pair<bool, int> v2 = isVirus(dna, m, e);
    if (!v1.first || !v2.first)
        return {false, 0};
    else if (abs(v1.second - v2.second) <= 1)
        return {true, v1.second + v2.second};
    else
        return {false, v1.second + v2.second};
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> dna(1 << k);
    while (n--) {
        for (int i = 0; i < dna.size(); ++i) {
            cin >> dna[i];
        }
        isVirus(dna, 0, dna.size()).first ? printf("yes\n") : printf("no\n");
    }
}
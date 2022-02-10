#include <bits/stdc++.h>

using namespace std;

bool check_similar(string &a, int startA, int endA, string &b, int startB, int endB) {
    if (endA == startA)
        return a[startA] == b[startB];
    int mA = (startA + endA) / 2;
    int mB = (startB + endB) / 2;
    return (check_similar(a, startA, mA, b, startB, mB) && check_similar(a, mA + 1, endA, b, mB + 1, endB)) || (check_similar(a, startA, mA, b, mB + 1, endB) && check_similar(a, mA + 1, endA, b, startB, mB));
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << (check_similar(a, 0, a.size() - 1, b, 0, b.size() - 1) ? "YES" : "NO");
}
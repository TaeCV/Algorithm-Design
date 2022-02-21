#include <bits/stdc++.h>

using namespace std;

long long N, i, a, b, c, tmpa, tmpb, tmpc;

int main() {
    cin >> N;
    a = 1;
    b = 1;
    c = 0;
    for (i = 2; i <= N; ++i) {
        tmpa = (a + c) % 100000007;
        tmpb = (a + b) % 100000007;
        tmpc = b % 100000007;
        a = tmpa;
        b = tmpb;
        c = tmpc;
    }
    cout << (a + b + c) % 100000007;
}